/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:53:08 by nharra            #+#    #+#             */
/*   Updated: 2019/10/07 14:46:08 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue		*ft_queue_new(void)
{
	t_queue *ptr;

	if (!(ptr = (t_queue *)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->size = 0;
	ptr->beg = NULL;
	ptr->end = NULL;
	return (ptr);
}
