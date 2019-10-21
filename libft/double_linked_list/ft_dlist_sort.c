/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:12:55 by nharra            #+#    #+#             */
/*   Updated: 2019/10/21 11:59:04 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_sort(t_dlist *beg, int (*cmp)(const void *, const void *))
{
	t_dlist *ptr;
	t_dlist *min;
	void	*save;

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
			save = beg->content;
			beg->content = min->content;
			min->content = save;
		}
		beg = beg->next;
	}
}
