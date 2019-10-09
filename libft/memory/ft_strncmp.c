/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:19:30 by nharra            #+#    #+#             */
/*   Updated: 2019/09/05 14:54:32 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i] && n)
	{
		if (s1[i] != s2[i])
			break ;
		++i;
		--n;
	}
	if (n == 0)
		return (0);
	else
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
