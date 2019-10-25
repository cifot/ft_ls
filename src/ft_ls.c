/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:10:38 by nharra            #+#    #+#             */
/*   Updated: 2019/10/25 20:40:31 by nharra           ###   ########.fr       */
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
	if (dirs)
	{
		if (ls_args)
			ft_putchar('\n');
		ls_dir((char *)dirs->content, flags, 1, NULL);
		ft_dlist_delone_link(&dirs, dirs);
	}
	while (dirs)
	{
		ft_putchar('\n');
		ls_dir((char *)dirs->content, flags, 1, NULL);
		ft_dlist_delone_link(&dirs, dirs);
	}
}

static void		print_one_dir(t_dlist *dirs, int flags, int ret)
{
	if (ret)
		ls_dir(strdup((char *)dirs->content), flags, 1, NULL);
	else
		ls_dir(strdup((char *)dirs->content), flags, 0, NULL);
	ft_dlist_simple_del(&dirs);
}

static int		just_print(t_dlist *ls_args, int flags)
{
	if (ls_args)
		check_sort(ls_args, flags);
	else
		ft_dlist_addfront(&ls_args, ".", 2, 2);
	ls_dir(ft_strdup("."), flags, 0, ls_args);
	return (1);
}

int				main(int argc, char **argv)
{
	int			flags;
	t_dlist		*ls_args;
	t_dlist		*dirs;
	int			ret;

	ls_args = NULL;
	if ((ret = make_flag_and_args(argv, &flags, &ls_args, NULL)) == -1)
		return (1);
	else if (ret != 0 && ls_args == NULL)
		return (0);
	if (flags & flag_d)
		return (just_print(ls_args, flags));
	if (ls_args)
	{
		check_sort(ls_args, flags);
		dirs = erase_dirs(&ls_args, flags);
		if (ls_args == NULL && ft_dlist_len(dirs) == 1)
			print_one_dir(dirs, flags, ret);
		else
			main_continue(ls_args, dirs, flags);
	}
	else
		call_ls_dir(ls_args, flags);
	return (argc - argc);
}
