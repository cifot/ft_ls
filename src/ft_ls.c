/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:10:38 by nharra            #+#    #+#             */
/*   Updated: 2019/10/09 18:36:07 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	int			flags;
	t_dlist		*ls_args;

	if (make_flag_and_args(argv, &flags, &ls_args) == -1)
		return (-1);
	if (ls_args)
	{
		if (check_sort(&ls_args) == -1)
			return (-1);
	}
	return (argc - argc);
}
