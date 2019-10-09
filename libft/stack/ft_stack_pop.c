/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:07:48 by nharra            #+#    #+#             */
/*   Updated: 2019/10/07 21:22:23 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_stack_pop(t_stack *st)
{
	void	*ptr;

	ptr = NULL;
	if (st && st->beg)
	{
		ptr = st->beg->content;
		ft_dlist_delone_link(&(st->beg), st->beg);
		st->size--;
	}
	return (ptr);
}
