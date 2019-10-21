/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_is_tagsort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:55:19 by nharra            #+#    #+#             */
/*   Updated: 2019/10/08 22:59:44 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dlist_is_tagsort(t_dlist *lst, int is_ascending)
{
	if (!lst)
		return (1);
	if (is_ascending)
	{
		while (lst->next)
		{
			if (lst->tag > lst->next->tag)
				return (0);
			lst = lst->next;
		}
	}
	else
	{
		while (lst->next)
		{
			if (lst->tag < lst->next->tag)
				return (0);
			lst = lst->next;
		}
	}
	return (1);
}
