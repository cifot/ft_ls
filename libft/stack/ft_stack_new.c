/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:01:45 by nharra            #+#    #+#             */
/*   Updated: 2019/10/07 21:23:18 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*ft_stack_new(void)
{
	t_stack *st;

	if (!(st = (t_stack *)malloc(sizeof(*st))))
		return (NULL);
	st->beg = NULL;
	st->size = 0;
	return (st);
}
