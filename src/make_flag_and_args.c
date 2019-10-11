/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flag_and_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:53:23 by nharra            #+#    #+#             */
/*   Updated: 2019/10/11 16:42:17 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

static int	add_flags(char *str, int *flags)
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
		else
			return (-1);
	}
	return (1);
}

t_dlist		*erase_dirs(t_dlist **lst)
{
	t_dlist		*dirs;
	DIR			*dir;
	t_dlist		*ptr;
	t_dlist		*next;

	ptr = *lst;
	dirs = NULL;
	while (ptr)
	{
		if ((dir = opendir((char *)ptr->content)))
		{
			closedir(dir);
			next = ptr->next;
			ft_dlist_push_link(&dirs, ptr->content, 0);
			ft_dlist_delone_link(lst, ptr);
			ptr = next;
		}
		else
			ptr = ptr->next;
	}
	return (dirs);
}

static int	check_invalid(char *name)
{
	struct stat st;

	if (stat(name, &st) == -1)
	{
		return (1);
	}
	return (0);
}

int			make_flag_and_args(char **argv, int *flags, t_dlist **ls_args)
{
	int		ret;
	int		i;
	int		len;

	i = 1;
	while (argv[i++])
	{
		if ((ret = add_flags(argv[i - 1], flags)) == -1)
			return (-1);
		if (ret == 0)
			break ;
	}
	while (argv[i++])
	{
		if (check_invalid(argv[i - 1]))
			continue ;
		len = ft_strlen(argv[i - 1]);
		if (ft_dlist_addfront(ls_args, argv[i - 1], len + 1, len) == NULL)
		{
			ft_dlist_simple_del(ls_args);
			return (-1);
		}
	}
	return (0);
}
