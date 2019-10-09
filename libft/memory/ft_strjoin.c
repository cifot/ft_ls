/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:18:20 by nharra            #+#    #+#             */
/*   Updated: 2019/09/10 14:14:21 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (!s1 || !s2 || !(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
