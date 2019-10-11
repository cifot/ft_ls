/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:43:16 by nharra            #+#    #+#             */
/*   Updated: 2019/10/11 18:29:02 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>

static t_dlist		*make_args(int flags, char *dirname)
{
	struct dirent	*cur_file;
	int				len;
	DIR				*dir;
	t_dlist			*lst;

	dir = opendir(dirname);
	lst = NULL;
	while ((cur_file = readdir(dir)))
	{
		if ((cur_file->d_name[0] == '.') && !(flags & flag_a))
			continue ;
		len = cur_file->d_namlen;
		ft_dlist_addfront(&lst, cur_file->d_name, len + 1, len);
	}
	closedir(dir);
	check_sort(lst, flags);
	return (lst);
}

int					call_strcmp(void *s1, void *s2)
{
	return (ft_strcmp((char *)s1, (char *)s2));
}

void				call_rec_continue(t_dlist *dirs, int flags,
						char *dirname, DIR *dir)
{
	t_dlist *ptr;

	closedir(dir);
	free(dirname);
	ptr = dirs;
	while (ptr)
	{
		ls_dir((char *)ptr->content, flags, 1, NULL);
		ptr = ptr->next;
	}
	ft_dlist_del_link(&dirs);
}

static void			call_rec(char *dirname, int flags, t_dlist *args)
{
	DIR				*dir;
	struct dirent	*cur_file;
	t_dlist			*dirs;
	int				len;
	char			*str;

	len = ft_strlen(dirname);
	dirs = NULL;
	if (!(dir = opendir(dirname)))
		return ;
	while ((cur_file = readdir(dir)))
	{
		if ((cur_file->d_name[0] == '.') && !(flags & flag_a))
			continue ;
		if ((cur_file->d_type == 4)
		&& ft_dlist_find(args, cur_file->d_name, call_strcmp))
		{
			args = args->next;
			str = ft_strdup(dirname);
			ft_join(&str, "/");
			ft_join(&str, cur_file->d_name);
			ft_dlist_push_link(&dirs, str, len + cur_file->d_namlen);
		}
	}
	call_rec_continue(dirs, flags, dirname, dir);
}

void				ls_dir(char *dirname, int flags,
						int write_name, t_dlist *args)
{
	DIR				*dir;

	if (!(dir = opendir(dirname)))
	{
		ft_printf("ls: %s: Permission denied\n", dirname);
		return ;
	}
	closedir(dir);
	if (!args)
		args = make_args(flags, dirname);
	if (write_name)
	{
		write(1, "\n", 1);
		write(1, dirname, ft_strlen(dirname));
		write(1, ":\n", 2);
	}
	if (flags & flag_l)
		hard_print(args);
	else
		simple_print(args);
	if (flags & flag_R)
		call_rec(dirname, flags, args);
	else
		free(dirname);
	ft_dlist_simple_del(&args);
}
