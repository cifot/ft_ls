/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:43:16 by nharra            #+#    #+#             */
/*   Updated: 2019/10/25 18:48:30 by nharra           ###   ########.fr       */
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
		write(1, "\n", 1);
		ls_dir((char *)ptr->content, flags, 1, NULL);
		ptr = ptr->next;
	}
	ft_dlist_del_link(&dirs);
}

char				*skip_dirs(char *str)
{
	char *tmp;

	tmp = str;
	while (*tmp)
		++tmp;
	while (*tmp != '/' && tmp != str)
		--tmp;
	if (*tmp == '/')
		++tmp;
	return (tmp);
}

static void			call_rec(char *dirname, int flags, t_dlist *args,
					t_dlist *dirs)
{
	struct stat		st;
	int				len;
	char			*str;

	len = ft_strlen(dirname);
	while (args)
	{
		if (lstat((char *)args->content, &st))
			stat((char *)args->content, &st);
		if (((skip_dirs((char *)args->content)[0] == '.') && !(flags & flag_a))
		|| !ft_strcmp(skip_dirs((char *)args->content), ".")
		|| !ft_strcmp(skip_dirs((char *)args->content), ".."))
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
	int				write_path;

	write_path = args ? 1 : 0;
	if (write_name)
		ft_printf("%s:\n", dirname);
	if (check_perm_denied(dirname))
		return ;
	if (!args)
		args = make_args(flags, dirname);
	if (flags & flag_l)
		hard_print(args, write_path, flags);
	else if (flags & flag_1)
		simple_print(args, write_path);
	else
		column_print(args, write_path);
	if ((flags & flag_R) && !(flags & flag_d))
		call_rec(dirname, flags, args, NULL);
	else
		free(dirname);
	ft_dlist_simple_del(&args);
}
