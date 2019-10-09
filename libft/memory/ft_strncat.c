/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:46:56 by nharra            #+#    #+#             */
/*   Updated: 2019/09/05 01:31:08 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_copy(char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		++i;
	}
	s1[i] = '\0';
}

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *s;

	s = s1;
	while (*s != '\0')
		++s;
	ft_copy(s, s2, n);
	return (s1);
}
