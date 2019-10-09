/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:25:29 by nharra            #+#    #+#             */
/*   Updated: 2019/09/11 17:51:12 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		result;
	size_t		i;

	i = 0;
	result = ft_strlen(src);
	while ((size > 0) && *dest)
	{
		--size;
		++dest;
		++result;
	}
	if (size > 1)
	{
		while (src[i] && (size > 1))
		{
			--size;
			*dest = src[i];
			++dest;
			++i;
		}
		*dest = '\0';
	}
	return (result);
}
