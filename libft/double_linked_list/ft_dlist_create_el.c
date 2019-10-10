/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_create_el.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:44:13 by nharra            #+#    #+#             */
/*   Updated: 2019/10/10 10:46:36 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlist_create_el(void *el, int tag)
{
	t_dlist *ptr;

	if (!(ptr = (t_dlist *)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->content = el;
	ptr->tag = tag;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}
