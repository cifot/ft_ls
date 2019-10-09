/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:01:38 by nharra            #+#    #+#             */
/*   Updated: 2019/09/11 20:17:22 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		if (!(str = (char *)malloc(ft_strlen(s) + 1)))
			return (NULL);
		while (s[i])
		{
			str[i] = f(i, s[i]);
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	else
	{
		return (NULL);
	}
}
