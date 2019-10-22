/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:10:38 by nharra            #+#    #+#             */
/*   Updated: 2019/10/22 19:10:24 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		call_ls_dir(t_dlist *ls_args, int flags)
{
	char *str;

	if (!(str = ft_strdup(".")))
		exit(0);
	ls_dir(str, flags, 0, ls_args);
}

static void		main_continue(t_dlist *ls_args, t_dlist *dirs, int flags)
{
	if (ls_args)
		call_ls_dir(ls_args, flags);
	while (dirs)
	{
		ls_dir((char *)dirs->content, flags, 1, NULL);
		ft_dlist_delone_link(&dirs, dirs);
	}
}

int				main(int argc, char **argv)
{
	int			flags;
	t_dlist		*ls_args;
	t_dlist		*dirs;

	ls_args = NULL;
	flags = 0;
	if (make_flag_and_args(argv, &flags, &ls_args, NULL) == -1)
		return (1);
	if (ls_args)
	{
		check_sort(ls_args, flags);
		dirs = erase_dirs(&ls_args);
		if (ls_args == NULL && ft_dlist_len(dirs) == 1)
		{
			ls_dir(strdup((char *)dirs->content), flags, 0, NULL);
			ft_dlist_simple_del(&dirs);
		}
		else
			main_continue(ls_args, dirs, flags);
	}
	else
		call_ls_dir(ls_args, flags);
	return (argc - argc);
}
