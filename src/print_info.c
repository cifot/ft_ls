/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:50:17 by nharra            #+#    #+#             */
/*   Updated: 2019/10/25 19:57:33 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>

static void		print_min_maj(struct stat *st, t_ls_info *info)
{
	char *str;

	put_nsym(info->size - info->max_minor - info->max_major - 2, ' ');
	if ((str = ft_lltostr(major(st->st_rdev), 10)))
	{
		put_nsym(info->max_major - ft_strlen(str), ' ');
		ft_putstr(str);
		free(str);
	}
	ft_putstr(", ");
	if ((str = ft_lltostr(minor(st->st_rdev), 10)))
	{
		put_nsym(info->max_minor - ft_strlen(str), ' ');
		ft_putstr(str);
		free(str);
	}
}

void			print_link_and_names(const char *filename, t_ls_info *info)
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
	put_nsym(info->count_link - ull_len_base(st.st_nlink, 10), ' ');
	if ((str = ft_ulltostr(st.st_nlink, 10)))
		ft_putstr(str);
	free(str);
	ft_putchar(' ');
	ft_putstr(user->pw_name);
	put_nsym(info->len_username - ft_strlen(user->pw_name), ' ');
	write(1, "  ", 2);
	ft_putstr(gr->gr_name);
	put_nsym(info->len_group - ft_strlen(gr->gr_name), ' ');
	write(1, "  ", 2);
}

void			print_blocks(const char *filename, t_ls_info *info)
{
	struct stat		st;
	char			*str;

	if (lstat(filename, &st))
		if (stat(filename, &st))
			return ;
	if (((st.st_mode & S_IFMT) == S_IFCHR) ||
	((st.st_mode & S_IFMT) == S_IFBLK))
		print_min_maj(&st, info);
	else
	{
		put_nsym(info->size - ll_len_base(st.st_size, 10), ' ');
		if ((str = ft_lltostr(st.st_size, 10)))
			ft_putstr(str);
		free(str);
	}
	ft_putchar(' ');
}

void			print_name_with_link(const char *filename, int print_full)
{
	struct stat		st;
	char			*str;

	if (lstat(filename, &st))
		if (stat(filename, &st))
			return ;
	if (!print_full)
		ft_putstr(filename);
	else
		print_filename(filename, 1);
	if ((st.st_mode & S_IFMT) == S_IFLNK)
	{
		write(1, " -> ", 4);
		if ((str = (char *)malloc(sizeof(*str) * st.st_size + 1)))
		{
			if (readlink(filename, str, st.st_size + 1) > 0)
				write(1, str, st.st_size);
			free(str);
		}
	}
}
