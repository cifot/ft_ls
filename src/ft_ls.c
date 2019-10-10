/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:10:38 by nharra            #+#    #+#             */
/*   Updated: 2019/10/10 11:22:21 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void  write_lst(t_dlist *ptr)
{
	while (ptr)
	{
		ft_printf("%s\n", (char *)ptr->content);
		ptr = ptr->next;
	}
}

int		main(int argc, char **argv)
{
	int			flags;
	t_dlist		*ls_args;

	if (make_flag_and_args(argv, &flags, &ls_args) == -1)
		return (-1);
	if (ls_args)
	{
		if (check_sort(ls_args, flags) == -1)
			return (-1);
	}
	write_lst(ls_args);
	return (argc - argc);
}
