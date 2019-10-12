/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:49:13 by nharra            #+#    #+#             */
/*   Updated: 2019/10/11 19:35:24 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlist_find(t_dlist const *lst, void *data,
							int (*f)(const void *, const void *))
{
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst && f(lst->content, data))
	{
		lst = lst->next;
	}
	return ((t_dlist *)lst);
}
