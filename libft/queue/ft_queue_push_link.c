/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_push_link.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:21:37 by nharra            #+#    #+#             */
/*   Updated: 2019/10/07 21:10:34 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_queue_push_link(t_queue *queue, void *el, int tag)
{
	if (!queue)
		return (-1);
	if (!ft_dlist_addfront_link(&(queue->beg), el, tag))
		return (-1);
	if (queue->size == 0)
		queue->end = queue->beg;
	queue->size += 1;
	return (0);
}
