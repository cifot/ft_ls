/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_simple_delone.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:04:25 by nharra            #+#    #+#             */
/*   Updated: 2019/09/13 13:11:27 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_simple_delone(t_dlist **lst, t_dlist *ptr)
{
	ft_dlist_delone(lst, ptr, free);
}
