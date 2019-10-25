/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:39:13 by nharra            #+#    #+#             */
/*   Updated: 2019/10/25 17:24:50 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void			check_sort(t_dlist *ls_args, int flags)
{
	if (!ls_args || !(ls_args->next))
		return ;
	if ((flags & flag_r) && (flags & flag_S))
		ft_dlist_sort(ls_args, cmp_size_descending);
	else if (flags & flag_S)
		ft_dlist_sort(ls_args, cmp_size_ascending);
	else if ((flags & flag_r) && (flags & flag_c) && (flags & flag_t))
		ft_dlist_sort(ls_args, cmp_ctime_descending);
	else if ((flags & flag_c) && (flags & flag_t))
		ft_dlist_sort(ls_args, cmp_ctime_ascending);
	else if ((flags & flag_r) && (flags & flag_t))
		ft_dlist_sort(ls_args, cmp_mtime_descending);
	else if (flags & flag_t)
		ft_dlist_sort(ls_args, cmp_mtime_ascending);
	else if (flags & flag_r)
		ft_dlist_sort(ls_args, void_revstrcmp);
	else
		ft_dlist_sort(ls_args, void_strcmp);
}
