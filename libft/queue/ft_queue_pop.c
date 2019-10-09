/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:45:24 by nharra            #+#    #+#             */
/*   Updated: 2019/10/07 21:09:32 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_queue_pop(t_queue *queue)
{
	void	*ptr;
	t_dlist	*del;

	ptr = NULL;
	if (queue && queue->end)
	{
		ptr = queue->end->content;
		del = queue->end;
		queue->end = queue->end->prev;
		ft_dlist_delone_link(&(queue->beg), del);
		queue->size--;
	}
	return (ptr);
}
