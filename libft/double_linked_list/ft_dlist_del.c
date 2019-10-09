/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:20:34 by nharra            #+#    #+#             */
/*   Updated: 2019/09/13 13:09:56 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_del(t_dlist **lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	while (*lst)
	{
		ft_dlist_delone(lst, *lst, del);
	}
	*lst = NULL;
}
