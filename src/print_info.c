/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:50:17 by nharra            #+#    #+#             */
/*   Updated: 2019/10/21 18:19:33 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>

void		print_type(const char *filename)
{
	struct stat		st;
	mode_t			stt;

	if (lstat(filename, &st))
		if (stat(filename, &st))
			return ;
	stt = st.st_mode & S_IFMT;
	if (stt == S_IFSOCK)
		ft_putchar('s');
	else if (stt == S_IFLNK)
		ft_putchar('l');
	else if (stt == S_IFBLK)
		ft_putchar('b');
	else if (stt == S_IFDIR)
		ft_putchar('d');
	else if (stt == S_IFCHR)
		ft_putchar('c');
	else if (stt == S_IFIFO)
		ft_putchar('p');
	else
		ft_putchar('-');
}

void		print_mode(const char *filename)
{
	struct stat st;
	char		*buf;
	int			i;
	const char	*mode;

	if (lstat(filename, &st))
		if (stat(filename, &st))
			return ;
	if (!(buf = (char *)malloc(sizeof(*buf) * 12)))
		return ;
	buf[9] = get_extatr(filename);
	buf[10] = ' ';
	buf[11] = '\0';
	mode = "rwxrwxrwx";
	i = 0;
	while (i < 9)
	{
		buf[i] = (st.st_mode & (1 << (8 - i))) ? mode[i] : '-';
		++i;
	}
	ft_putstr(buf);
	free(buf);
}

void		print_link_and_names(const char *filename, t_ls_info *info)
{
	struct stat		st;
	char			*str;
	struct group	*gr;
	struct passwd	*user;

	if (lstat(filename, &st))
		if (stat(filename, &st))
			return ;
	if (!(gr = getgrgid(st.st_gid)))
		return ;
	if (!(user = getpwuid(st.st_uid)))
		return ;
	put_nsym(ull_len_base(info->count_link, 10) -
		ull_len_base(st.st_nlink, 10), ' ');
	if ((str = ft_ulltostr(st.st_nlink, 10)))
		ft_putstr(str);
	free(str);
	ft_putchar(' ');
	put_nsym(info->len_username - ft_strlen(user->pw_name), ' ');
	ft_putstr(user->pw_name);
	write(1, "  ", 2);
	put_nsym(info->len_group - ft_strlen(gr->gr_name), ' ');
	ft_putstr(gr->gr_name);
	write(1, "  ", 2);
}

void		print_time_and_blocks(const char *filename, t_ls_info *info)
{
	struct stat		st;
	char			*str;

	put_nsym(ll_len_base(info->size, 10) - ll_len_base(st.st_size, 10), ' ');
	if ((str = ft_lltostr(st.st_size, 10)))
		ft_putstr(str);
	free(str);
	ft_putchar(' ');
	if (lstat(filename, &st))
		if (stat(filename, &st))
			return ;
	if (!(str = ctime(&st.st_mtimespec.tv_sec)))
		return ;
	write(1, str + 4, ft_strlen(str) - 13);
	write(1, " ", 1);
}

void		print_name_with_link(const char *filename, int print_full)
{
	struct stat		st;
	char			*str;

	if (lstat(filename, &st))
		if (stat(filename, &st))
			return ;
	if (print_full)
		ft_printf("%s", filename);
	else
		print_filename(filename);
	if (!lstat(filename, &st) && ((st.st_mode & S_IFMT) == S_IFLNK))
	{
		write(1, " -> ", 4);
		if ((str = (char *)malloc(sizeof(*str) * st.st_size + 1)))
			if (readlink(filename, str, st.st_size + 1) > 0)
				write(1, str, st.st_size);
		free(str);
	}
}
