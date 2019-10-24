/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flag_and_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:53:23 by nharra            #+#    #+#             */
/*   Updated: 2019/10/24 16:38:14 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

static int		add_flags(char *str, int *flags)
{
	if (*str != '-' || str[1] == '\0')
		return (0);
	if (!ft_strcmp(str, "--"))
		return (2);
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
			print_illegal_option(*str);
			return (-1);
		}
	}
	return (1);
}

static int		check_invalid(char *name, t_dlist **error)
{
	struct stat st;


	if (lstat(name, &st) && stat(name, &st))
	{
		ft_dlist_addfront_link(error, name, 0);
		return (1);
	}
	return (0);
}

static int		print_error(t_dlist **error)
{
	t_dlist		*ptr;
	int			count;

	ft_dlist_sort(*error, void_strcmp);
	ptr = *error;
	count = 0;
	while (ptr)
	{
		ft_putstr_fd("ls: ", 2);
		if (ft_strcmp(ptr->content, ""))
			ft_putstr_fd(ptr->content, 2);
		else
		{
			ft_putstr_fd("fts_open", 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			exit(1);
		}
		ft_putstr_fd(": No such file or directory\n", 2);
		ptr = ptr->next;
		++count;
	}
	ft_dlist_del_link(error);
	return (count);
}

int				make_flag_and_args(char **argv, int *flags,
					t_dlist **ls_args, t_dlist *error)
{
	int		ret;
	int		i;
	int		len;

	*flags = 0;
	i = 0;
	while (argv[++i])
	{
		if ((ret = add_flags(argv[i], flags)) == -1)
			return (-1);
		else
		{
			if (ret == 2)
				++i;
			if (ret != 1)
				break;
		}
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
	return (print_error(&error));
}
