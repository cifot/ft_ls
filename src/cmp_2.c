/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:48:24 by nharra            #+#    #+#             */
/*   Updated: 2019/10/24 18:00:05 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int		cmp_size_ascending(const void *s1, const void *s2)
{
	struct stat		info1;
	struct stat		info2;

	if (lstat((char *)s1, &info1))
		stat((char *)s1, &info1);
	if (lstat((char *)s2, &info2))
		stat((char *)s2, &info2);
	if (info1.st_size == info2.st_size)
		return (ft_strcmp((char *)s1, (char *)s2));
	else
		return (info2.st_size - info1.st_size);
}

int		cmp_size_descending(const void *s1, const void *s2)
{
	return (cmp_size_ascending(s2, s1));
}
