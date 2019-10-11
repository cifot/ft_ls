/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:12:55 by nharra            #+#    #+#             */
/*   Updated: 2019/10/11 16:35:16 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_sort(t_dlist *beg, long (*cmp)(const void *, const void *))
{
	t_dlist *ptr;
	t_dlist *min;

	if (!beg || !(beg->next))
		return ;
	while (beg->next)
	{
		min = beg;
		ptr = beg->next;
		while (ptr)
		{
			if (cmp(min->content, ptr->content) > 0)
				min = ptr;
			ptr = ptr->next;
		}
		if (min != beg)
		{
			ft_swap_link(&(min->content), &(beg->content));
			ft_swap_int(&(min->tag), &(beg->tag));
		}
		beg = beg->next;
	}
}
