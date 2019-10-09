/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:32:02 by nharra            #+#    #+#             */
/*   Updated: 2019/09/10 15:44:46 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*tmp;
	t_list	*begin_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = f(lst);
	if (!(begin_list = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	current = begin_list;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(current->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		current = current->next;
		lst = lst->next;
	}
	return (begin_list);
}
