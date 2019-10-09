/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push_link.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:14:52 by nharra            #+#    #+#             */
/*   Updated: 2019/10/07 21:19:46 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_stack_push_link(t_stack *st, void *el, int tag)
{
	if (!st)
		return (-1);
	if (!ft_dlist_addfront_link(&(st->beg), el, tag))
		return (-1);
	st->size++;
	return (0);
}
