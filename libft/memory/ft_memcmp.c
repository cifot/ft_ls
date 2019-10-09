/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:33:03 by nharra            #+#    #+#             */
/*   Updated: 2019/09/05 18:09:56 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (((unsigned char*)s1)[i] != ((unsigned char*)s2)[i])
			break ;
		++i;
	}
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
