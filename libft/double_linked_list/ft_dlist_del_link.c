/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_del_link.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:08:05 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 10:53:30 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_del_link(t_dlist **lst)
{
	if (lst == NULL)
		return ;
	while (*lst)
	{
		ft_dlist_delone_link(lst, *lst);
	}
	*lst = NULL;
}
