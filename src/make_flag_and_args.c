/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flag_and_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:53:23 by nharra            #+#    #+#             */
/*   Updated: 2019/10/22 19:09:15 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

static int		add_flags(char *str, int *flags)
{
	if (*str != '-' || *(str + 1) == '\0')
		return (0);
	while (*(++str))
	{
		if (*str == 'R')
			*flags |= flag_R;
		else if (*str == 'a')
			*flags |= flag_a;
		else if (*str == 'r')
			*flags |= flag_r;
		else if (*str == 'l')
			*flags |= flag_l;
		else if (*str == 't')
			*flags |= flag_t;
		else if (*str != '1')
		{
			ft_putstr_fd("ls: illegal option --", 2);
			ft_putchar_fd(*str, 2);
			ft_putstr_fd("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 2);
			return (-1);
		}
	}
	return (1);
}

t_dlist			*erase_dirs(t_dlist **lst)
{
	t_dlist		*dirs;
	DIR			*dir;
	t_dlist		*ptr;
	t_dlist		*next;
	int			tag;

	ptr = *lst;
	dirs = NULL;
	while (ptr)
	{
		if ((dir = opendir((char *)ptr->content)))
		{
			closedir(dir);
			next = ptr->next;
			tag = ptr->tag;
			ft_dlist_push_link(&dirs, ptr->content, tag);
			ft_dlist_delone_link(lst, ptr);
			ptr = next;
		}
		else
			ptr = ptr->next;
	}
	return (dirs);
}

static int		check_invalid(char *name, t_dlist **error)
{
	struct stat st;

	if (stat(name, &st) == -1)
	{
		ft_dlist_addfront_link(error, name, 0);
		return (1);
	}
	return (0);
}

static void		print_error(t_dlist **error)
{
	t_dlist *ptr;

	ft_dlist_sort(*error, void_strcmp);
	ptr = *error;
	while (ptr)
	{
		ft_printf("ls: %s: No such file or directory\n", ptr->content);
		ptr = ptr->next;
	}
	ft_dlist_del_link(error);
}

int				make_flag_and_args(char **argv, int *flags,
					t_dlist **ls_args, t_dlist *error)
{
	int		ret;
	int		i;
	int		len;

	i = 0;
	while (argv[++i])
	{
		if ((ret = add_flags(argv[i], flags)) == -1)
			return (-1);
		if (ret == 0)
			break ;
	}
	while (argv[i])
	{
		if (check_invalid(argv[i++], &error))
			continue ;
		len = ft_strlen(argv[i - 1]);
		if (ft_dlist_addfront(ls_args, argv[i - 1], len + 1, len) == NULL)
		{
			ft_dlist_simple_del(ls_args);
			return (-1);
		}
	}
	print_error(&error);
	return (0);
}
