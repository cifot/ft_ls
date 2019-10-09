/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:03:03 by nharra            #+#    #+#             */
/*   Updated: 2019/09/05 15:02:05 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t a)
{
	size_t i;

	i = 0;
	while (i < a && src[i])
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	while (i < a)
	{
		((unsigned char *)dest)[i] = '\0';
		++i;
	}
	return (dest);
}
