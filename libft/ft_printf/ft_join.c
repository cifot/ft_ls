/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 10:20:04 by nharra            #+#    #+#             */
/*   Updated: 2019/10/21 12:56:11 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_nsym(int count, char sym)
{
	char	*s;
	size_t	size;

	size = count + 1;
	if (count <= 0)
		return (NULL);
	if (!(s = (char *)malloc(size)))
		return (NULL);
	s[--size] = '\0';
	while (size--)
		s[size] = sym;
	return (s);
}

char	*ft_join_beg(char **s1, const char *s2)
{
	size_t		len1;
	size_t		len2;
	char		*s;
	size_t		i;

	if (!s1 || !s2 || (i = 0))
		return (NULL);
	if (!(*s1))
		return (*s1 = ft_strdup(s2));
	len1 = ft_strlen(*s1);
	if ((len2 = ft_strlen(s2)) == 0)
		return (*s1);
	if (!(s = (char *)malloc(len1 + len2 + 1)))
		return (NULL);
	while (i < len2)
	{
		s[i] = s2[i];
		++i;
	}
	while (i++ <= len1 + len2)
		s[i - 1] = (*s1)[i - 1 - len2];
	free(*s1);
	*s1 = s;
	return (s);
}

char	*ft_join(char **s1, const char *s2)
{
	size_t		len1;
	size_t		len2;
	char		*s;
	size_t		i;

	if (!s1 || !s2 || (i = 0))
		return (NULL);
	if (!(*s1))
		return (*s1 = ft_strdup(s2));
	len1 = ft_strlen(*s1);
	if ((len2 = ft_strlen(s2)) == 0)
		return (*s1);
	if (!(s = (char *)malloc(len1 + len2 + 1)))
		return (NULL);
	while (i < len1)
	{
		s[i] = (*s1)[i];
		++i;
	}
	while (i++ <= len1 + len2)
		s[i - 1] = s2[i - 1 - len1];
	free(*s1);
	*s1 = s;
	return (s);
}
