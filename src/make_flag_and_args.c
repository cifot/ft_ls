/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flag_and_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:53:23 by nharra            #+#    #+#             */
/*   Updated: 2019/10/09 18:35:14 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	add_flags(char *str, int *flags)
{
	if (*str != '-' || *(str + 1) == '\0')
		return(0);
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

int			make_flag_and_args(char **argv, int *flags, t_dlist **ls_args)
{
	int		ret;
	int		i;

	*ls_args = NULL;
	*flags = 0;
	i = 1;
	while (argv[i])
	{
		if ((ret = add_flags(argv[i], flags)) == -1)
			return (-1);
		if (ret == 0)
			break ;
		++i;
	}
	while (argv[i])
	{
		if (ft_dlist_addfront_link(ls_args, (void *)argv[i], 0) == NULL)
		{
			ft_dlist_del_link(ls_args);
			return(-1);
		}
		++i;
	}
	return (0);
}
