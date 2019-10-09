/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:30:12 by nharra            #+#    #+#             */
/*   Updated: 2019/10/09 17:58:06 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlist_sort(t_dlist *beg, int (*cmp)(void *, void *))
{
	t_dlist		*ptr;
	void		*save;

	if (!beg || !(beg->next))
		return ;
	while (beg->next)
	{
		ptr = beg->next;
		while (ptr)
		{
			if (cmp(beg->content, ptr->content) > 0)
			{
				save = beg->content;
				beg->content = ptr->content;
				ptr->content = save;
			}
			ptr = ptr->next;
		}
		beg = beg->next;
	}
}
