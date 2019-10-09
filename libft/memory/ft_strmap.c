/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:57:10 by nharra            #+#    #+#             */
/*   Updated: 2019/09/10 13:58:56 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
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
			str[i] = f(s[i]);
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
