/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_after.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:38:19 by nharra            #+#    #+#             */
/*   Updated: 2019/10/10 10:43:38 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_add_after(t_dlist *after, t_dlist *el)
{
	if (!after || !el)
		return ;
	if (after->next)
		after->next->prev = el;
	el->next = after->next;
	el->prev = after;
	after->next = el;
}
