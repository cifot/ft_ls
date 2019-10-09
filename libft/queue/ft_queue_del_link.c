/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_del_link.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:59:23 by nharra            #+#    #+#             */
/*   Updated: 2019/10/07 21:07:16 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_queque_del_link(t_queue **queue)
{
	if (queue && *queue)
	{
		ft_dlist_del_link(&((*queue)->beg));
		free(*queue);
	}
	if (queue)
		*queue = NULL;
}
