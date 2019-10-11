/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:10:38 by nharra            #+#    #+#             */
/*   Updated: 2019/10/11 16:40:59 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	main_continue(t_dlist *ls_args, t_dlist *dirs, int flags)
{
	char		*str;

	if (ls_args)
	{
		if (!(str = strdup(".")))
			exit(0);
		ls_dir(str, flags, 0, ls_args);
	}
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
	if (make_flag_and_args(argv, &flags, &ls_args) == -1)
		return (-1);
	if (ls_args)
	{
		check_sort(ls_args, flags);
		dirs = erase_dirs(&ls_args);
	}
	if (ls_args == NULL && ft_dlist_len(dirs) == 1)
		ls_dir(strdup((char *)dirs->content), flags, 0, NULL);
	else
		main_continue(ls_args, dirs, flags);
	return (argc - argc);
}
