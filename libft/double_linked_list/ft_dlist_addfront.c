/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_addfront.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:45:03 by nharra            #+#    #+#             */
/*   Updated: 2019/10/11 17:46:51 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlist_addfront(t_dlist **lst, void *data, size_t size, int tag)
{
	t_dlist		*ptr;

	if (!lst || !(ptr = (t_dlist *)malloc(sizeof(*ptr))))
		return (NULL);
	if (!(ptr->content = (void *)malloc(size)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(ptr->content, data, size);
	ptr->tag = tag;
	ptr->prev = NULL;
	ptr->next = *lst;
	if ((*lst) != NULL)
		(*lst)->prev = ptr;
	*lst = ptr;
	return (*lst);
}
