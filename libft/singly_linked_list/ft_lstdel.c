/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:14:31 by nharra            #+#    #+#             */
/*   Updated: 2019/09/10 15:35:52 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*prev;

	if (alst == NULL || del == NULL || *alst == NULL)
		return ;
	next = (*alst)->next;
	prev = (*alst);
	while (next != NULL)
	{
		ft_lstdelone(&prev, del);
		prev = next;
		next = next->next;
	}
	ft_lstdelone(&prev, del);
	*alst = NULL;
}
