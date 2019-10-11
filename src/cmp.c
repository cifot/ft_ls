/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:48:49 by nharra            #+#    #+#             */
/*   Updated: 2019/10/11 16:34:05 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>

long	void_strcmp(const void *s1, const void *s2)
{
	return (ft_strcmp((char *)s1, (char *)s2));
}

long	void_revstrcmp(const void *s1, const void *s2)
{
	return (ft_strcmp((char *)s2, (char *)s1));
}

long	cmp_time_descending(const void *s1, const void *s2)
{
	struct stat		info1;
	struct stat		info2;

	stat((char *)s1, &info1);
	stat((char *)s2, &info2);
	if (info1.st_mtimespec.tv_sec == info2.st_mtimespec.tv_sec)
		return (ft_strcmp((char *)s1, (char *)s2));
	return (info1.st_mtimespec.tv_sec - info2.st_mtimespec.tv_sec);
}

long	cmp_time_ascending(const void *s1, const void *s2)
{
	struct stat		info1;
	struct stat		info2;

	stat((char *)s1, &info1);
	stat((char *)s2, &info2);
	if (info1.st_mtimespec.tv_sec == info2.st_mtimespec.tv_sec)
		return (ft_strcmp((char *)s2, (char *)s1));
	return (info2.st_mtimespec.tv_sec - info1.st_mtimespec.tv_sec);
}
