/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_delone_link.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:11:08 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 10:54:06 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_delone_link(t_dlist **lst, t_dlist *ptr)
{
	if (ptr && lst && *lst)
	{
		if (ptr->prev)
			ptr->prev->next = ptr->next;
		if (ptr->next)
			ptr->next->prev = ptr->prev;
		if (*lst == ptr)
			*lst = ptr->next;
		free(ptr);
	}
}
