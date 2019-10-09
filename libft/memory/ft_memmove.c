/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:28:38 by nharra            #+#    #+#             */
/*   Updated: 2019/09/10 11:47:11 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t i;

	if (dst == src)
		return (dst);
	if (src > dst)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			++i;
		}
	}
	else
	{
		i = n;
		while (i--)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	return (dst);
}
