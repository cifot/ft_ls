/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:48:49 by nharra            #+#    #+#             */
/*   Updated: 2019/10/10 15:41:41 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>

long	cmp_error(const void *s1, const void *s2)
{
	struct stat		info;
	int				ret_1;
	int				ret_2;

	ret_1 = stat((char *)s1, &info);
	ret_2 = stat((char *)s2, &info);
	if (ret_1 == ret_2)
		return (ft_strcmp((char *)s1, (char *)s2));
	else if (ret_1 == -1)
		return (-1);
	else
		return (1);
}

long	void_strcmp(const void *s1, const void *s2)
{
	return (ft_strcmp((const char *)s1, (const char *)s2));
}

long	void_revstrcmp(const void *s1, const void *s2)
{
	return (ft_strcmp((const char *)s2, (const char *)s1));
}

long	cmp_time_ascending(const void *s1, const void *s2)
{
	struct stat		info1;
	struct stat		info2;
	DIR				*ret1;
	DIR				*ret2;

	ret1 = opendir((char *)s1);
	ret2 = opendir((char *)s2);
	stat((char *)s1, &info1);
	stat((char *)s2, &info2);
	if (ret1 && !ret2)
		return (1);
	if (ret1 && ret2)
		return (void_strcmp(s1, s2));
	if (!ret1 && ret2)
		return (-1);
	if (info1.st_mtimespec.tv_sec == info2.st_mtimespec.tv_sec)
		return (ft_strcmp((char *)s1, (char *)s2));
	return (info1.st_mtimespec.tv_sec - info2.st_mtimespec.tv_sec);
}

long	cmp_time_descending(const void *s1, const void *s2)
{
	struct stat		info1;
	struct stat		info2;
	DIR				*ret1;
	DIR				*ret2;

	ret1 = opendir((char *)s1);
	ret2 = opendir((char *)s2);
	stat((char *)s1, &info1);
	stat((char *)s2, &info2);
	if (ret1 && !ret2)
		return (1);
	if (ret1 && ret2)
		return (void_revstrcmp(s1, s2));
	if (!ret1 && ret2)
		return (-1);
	if (info1.st_mtimespec.tv_sec == info2.st_mtimespec.tv_sec)
		return (void_revstrcmp(s1, s2));
	return (info2.st_mtimespec.tv_sec - info1.st_mtimespec.tv_sec);
}
