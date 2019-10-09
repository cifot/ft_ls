/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:16:50 by nharra            #+#    #+#             */
/*   Updated: 2019/09/05 14:31:30 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (dst != src)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			++i;
		}
	}
	return (dst);
}
