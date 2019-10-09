/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:20:38 by nharra            #+#    #+#             */
/*   Updated: 2019/09/04 19:04:36 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*save;

	save = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			save = (char*)s + i;
		++i;
	}
	if (s[i] == c)
		return ((char*)s + i);
	else
		return (save);
}
