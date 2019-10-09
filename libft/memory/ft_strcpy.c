/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:02:38 by nharra            #+#    #+#             */
/*   Updated: 2019/09/12 15:47:59 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*save;
	size_t	i;

	i = 0;
	save = dest;
	while (src[i])
	{
		*dest = src[i];
		++dest;
		++i;
	}
	*dest = '\0';
	return (save);
}
