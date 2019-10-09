/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:38:03 by nharra            #+#    #+#             */
/*   Updated: 2019/09/05 11:52:37 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *str;

	if (!(str = (char *)malloc(ft_strlen(s1) + 1)))
	{
		return (NULL);
	}
	else
	{
		ft_strcpy(str, s1);
		return (str);
	}
}
