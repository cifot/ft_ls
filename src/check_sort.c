/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:39:13 by nharra            #+#    #+#             */
/*   Updated: 2019/10/11 15:36:21 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

static void		skip_invalid(t_dlist *lst, t_dlist **ptr)
{
	struct stat		info;

	while (lst && (stat((char *)lst->content, &info) == -1))
		lst = lst->next;
	*ptr = lst;
}

void			check_sort(t_dlist *ls_args, int flags)
{
	t_dlist *ptr;

	skip_invalid(ls_args, &ptr);
	if (!ptr)
		return ;
	if ((flags & flag_r) && (flags & flag_t))
		ft_dlist_sort(ptr, cmp_time_descending);
	else if (flags & flag_t)
		ft_dlist_sort(ptr, cmp_time_ascending);
	else if (flags & flag_r)
		ft_dlist_sort(ptr, void_revstrcmp);
	else
		ft_dlist_sort(ptr, void_strcmp);
}
