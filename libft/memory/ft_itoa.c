/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:10:54 by nharra            #+#    #+#             */
/*   Updated: 2019/09/10 11:27:30 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	num_len(int n, int *rank)
{
	int		len;
	long	ln;

	*rank = 1;
	if (n == 0)
		return (2);
	len = 1;
	ln = n;
	if (n < 0)
	{
		ln = -ln;
		++len;
	}
	while (ln > 9)
	{
		++len;
		ln /= 10;
		*rank *= 10;
	}
	++len;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		rank;
	long	lnum;

	if (!(str = (char*)malloc(num_len(n, &rank))))
		return (NULL);
	i = 0;
	lnum = n;
	if (n < 0)
	{
		str[i++] = '-';
		lnum = -lnum;
	}
	while (rank)
	{
		str[i++] = ((lnum / rank) % 10) + '0';
		rank /= 10;
	}
	str[i] = '\0';
	return (str);
}
