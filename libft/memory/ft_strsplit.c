/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:04:33 by czena             #+#    #+#             */
/*   Updated: 2019/09/08 12:05:23 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_move(char *s, int *i, char w)
{
	int start;

	start = 0;
	while (s[*i] == w)
		*i = *i + 1;
	start = *i;
	while (s[*i] != w && s[*i] != '\0')
		*i = *i + 1;
	return (start);
}

static void		ft_words(char *s, int *n, char w)
{
	int		i;
	int		start;

	i = 0;
	start = ft_move(s, &i, w);
	if (s[start] != '\0')
	{
		*n = *n + 1;
		ft_words(&s[i], n, w);
	}
}

static void		ft_clear_result(char **result, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(result[i]);
		result[i] = (void*)0;
		i++;
	}
	free(result);
	result = (void*)0;
}

static int		ft_word(char *s, char w, char **res, int *n)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	ft_move(s, &size, w);
	if ((res[*n] = (char*)malloc(sizeof(char) * (size + 1))) == (void*)0)
	{
		ft_clear_result(res, *n);
		return (0);
	}
	while (s[i] != w && s[i] != '\0')
	{
		res[*n][i] = s[i];
		i++;
	}
	res[*n][size] = '\0';
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		n;
	int		i;
	int		start;
	int		end;

	n = 0;
	i = 0;
	start = 0;
	end = 0;
	if (s == (void*)0)
		return ((void*)0);
	ft_words((char*)s, &n, c);
	if ((result = (char**)malloc(sizeof(char*) * (n + 1))) == (void*)0)
		return ((void*)0);
	if (n != 0)
		while (i < n)
		{
			start = ft_move((char *)s, &end, c);
			if (ft_word(&((char *)s)[start], c, result, &i) == 0)
				return ((void*)0);
			i++;
		}
	result[i] = (void*)0;
	return (&result[0]);
}
