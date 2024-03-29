/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:48:49 by nharra            #+#    #+#             */
/*   Updated: 2019/10/25 17:07:36 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int		void_strcmp(const void *s1, const void *s2)
{
	return (ft_strcmp((char *)s1, (char *)s2));
}

int		void_revstrcmp(const void *s1, const void *s2)
{
	return (ft_strcmp((char *)s2, (char *)s1));
}

int		cmp_mtime_descending(const void *s1, const void *s2)
{
	return (cmp_mtime_ascending(s2, s1));
}

int		cmp_mtime_ascending(const void *s1, const void *s2)
{
	struct stat		info1;
	struct stat		info2;

	if (lstat((char *)s1, &info1))
		stat((char *)s1, &info1);
	if (lstat((char *)s2, &info2))
		stat((char *)s2, &info2);
	if (info1.st_mtimespec.tv_sec == info2.st_mtimespec.tv_sec)
		return (ft_strcmp((char *)s1, (char *)s2));
	if (info1.st_mtimespec.tv_sec < info2.st_mtimespec.tv_sec)
		return (1);
	else
		return (-1);
}
