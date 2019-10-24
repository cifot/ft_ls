/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:12:41 by nharra            #+#    #+#             */
/*   Updated: 2019/10/24 16:41:26 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

static char		get_type(const char *filename)
{
	struct stat		st;
	mode_t			stt;

	if (lstat(filename, &st))
		if (stat(filename, &st))
			return ('-');
	stt = st.st_mode & S_IFMT;
	if (stt == S_IFSOCK)
		return ('s');
	else if (stt == S_IFLNK)
		return ('l');
	else if (stt == S_IFBLK)
		return ('b');
	else if (stt == S_IFDIR)
		return ('d');
	else if (stt == S_IFCHR)
		return ('c');
	else if (stt == S_IFIFO)
		return ('p');
	else
		return ('-');
}

static char		check_t(mode_t mode)
{
	if (mode & 511)
		return ('t');
	else
		return ('T');
}

static char		check_s(mode_t mode)
{
	if (mode & 511)
		return ('s');
	else
		return ('S');
}

void			print_mode(const char *filename)
{
	struct stat st;
	char		*buf;
	int			i;
	const char	*mode;

	if (lstat(filename, &st))
		if (stat(filename, &st))
			return ;
	if (!(buf = (char *)malloc(sizeof(*buf) * 13)))
		return ;
	buf[0] = get_type(filename);
	buf[10] = get_extatr(filename);
	buf[11] = ' ';
	buf[12] = '\0';
	mode = "rwxrwxrwx";
	i = -1;
	while (++i < 9)
	{
		if (((i + 1) % 3) == 0 && (st.st_mode & (1 << (11 - i / 3))))
			buf[i + 1] = (i == 8) ? check_t(st.st_mode) : check_s(st.st_mode);
		else
			buf[i + 1] = (st.st_mode & (1 << (8 - i))) ? mode[i] : '-';
	}
	ft_putstr(buf);
	free(buf);
}
