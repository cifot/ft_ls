/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:43:16 by nharra            #+#    #+#             */
/*   Updated: 2019/10/14 16:09:16 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

static t_dlist		*make_args(int flags, char *dirname)
{
	struct dirent	*cur_file;
	int				len;
	DIR				*dir;
	t_dlist			*lst;
	char			*str;

	dir = opendir(dirname);
	lst = NULL;
	len = ft_strlen(dirname);
	while ((cur_file = readdir(dir)))
	{
		if ((cur_file->d_name[0] == '.') && !(flags & flag_a))
			continue ;
		str = ft_strdup(cur_file->d_name);
		ft_join_beg(&str, "/");
		ft_join_beg(&str, dirname);
		ft_dlist_addfront_link(&lst, str, len + cur_file->d_namlen + 2);
	}
	closedir(dir);
	check_sort(lst, flags);
	return (lst);
}

void				call_rec_continue(t_dlist *dirs, int flags,
						char *dirname)
{
	t_dlist *ptr;

	free(dirname);
	ptr = dirs;
	while (ptr)
	{
		ls_dir((char *)ptr->content, flags, 1, NULL);
		ptr = ptr->next;
	}
	ft_dlist_del_link(&dirs);
}

static char			*skip_dirs(char *str)
{
	while(*str)
		++str;
	while (*str != '/')
		--str;
	++str;
	return (str);
}

static void			call_rec(char *dirname, int flags, t_dlist *args)
{
	struct stat		st;
	t_dlist			*dirs;
	int				len;
	char			*str;

	len = ft_strlen(dirname);
	dirs = NULL;
	while (args && !stat((char *)args->content, &st))
	{
		if ((skip_dirs((char *)args->content)[0] == '.') && !(flags & flag_a))
		{
			args = args->next;
			continue ;
		}
		if (((st.st_mode & S_IFMT) == S_IFDIR))
		{
			str = ft_strdup((char *)args->content);
			ft_dlist_push_link(&dirs, str, args->tag);
		}
		args = args->next;
	}
	call_rec_continue(dirs, flags, dirname);
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
