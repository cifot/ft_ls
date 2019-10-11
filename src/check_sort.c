/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:39:13 by nharra            #+#    #+#             */
/*   Updated: 2019/10/11 17:14:40 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


void			check_sort(t_dlist *ls_args, int flags)
{
	if ((flags & flag_r) && (flags & flag_t))
		ft_dlist_sort(ls_args, cmp_time_descending);
	else if (flags & flag_t)
		ft_dlist_sort(ls_args, cmp_time_ascending);
	else if (flags & flag_r)
		ft_dlist_sort(ls_args, void_revstrcmp);
	else
		ft_dlist_sort(ls_args, void_strcmp);
}
