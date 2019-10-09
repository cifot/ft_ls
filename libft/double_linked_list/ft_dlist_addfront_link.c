/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_addfront_link.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:35:14 by nharra            #+#    #+#             */
/*   Updated: 2019/10/07 15:43:24 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlist_addfront_link(t_dlist **lst, void *data, int tag)
{
	t_dlist		*ptr;

	if (!lst || !(ptr = (t_dlist *)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->content = data;
	ptr->tag = tag;
	ptr->prev = NULL;
	ptr->next = *lst;
	if (*lst != NULL)
		(*lst)->prev = ptr;
	*lst = ptr;
	return (*lst);
}
