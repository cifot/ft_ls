/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:11:49 by nharra            #+#    #+#             */
/*   Updated: 2019/09/10 14:13:40 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s || !(str = (char *)malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	return ((char *)ft_memcpy(str, s + start, len));
}
