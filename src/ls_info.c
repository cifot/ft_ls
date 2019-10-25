/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:55:04 by nharra            #+#    #+#             */
/*   Updated: 2019/10/25 18:58:13 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

t_ls_info		*new_ls_info(void)
{
	t_ls_info	*info;

	if (!(info = (t_ls_info *)malloc(sizeof(*info))))
		return (NULL);
	info->count_link = 0;
	info->len_group = 0;
	info->size = 0;
	info->len_username = 0;
	info->max_major = -1;
	info->max_minor = -1;
	return (info);
}

static void		size_check(struct stat *st, t_ls_info *info)
{
	dev_t	save;

	if (((st->st_mode & S_IFMT) == S_IFCHR) ||
	((st->st_mode & S_IFMT) == S_IFBLK))
	{
		if ((save = minor(st->st_rdev)) > info->max_minor)
			info->max_minor = save;
		if ((save = major(st->st_rdev)) > info->max_major)
			info->max_major = save;
	}
	else
	{
		if (st->st_size > info->size)
			info->size = st->st_size;
	}
}

static void		check_file(char *filename, t_ls_info *info)
{
	struct stat		st;
	struct group	*gr;
	struct passwd	*user;
	size_t			len;

	if (lstat(filename, &st))
		if (stat(filename, &st))
			return ;
	if (!(gr = getgrgid(st.st_gid)))
		return ;
	if (!(user = getpwuid(st.st_uid)))
		return ;
	if (st.st_nlink > info->count_link)
		info->count_link = st.st_nlink;
	if ((len = ft_strlen(gr->gr_name)) > info->len_group)
		info->len_group = len;
	if ((len = ft_strlen(user->pw_name)) > info->len_username)
		info->len_username = len;
	size_check(&st, info);
}

t_ls_info		*init_ls_info(t_dlist *args)
{
	t_ls_info		*info;
	long			len_min_maj;
	long			len_size;

	if (!(info = new_ls_info()))
		return (NULL);
	while (args)
	{
		check_file((char *)args->content, info);
		args = args->next;
	}
	len_size = ll_len_base(info->size, 10);
	if (info->max_major != -1 && info->max_minor != -1)
	{
		++len_size;
		len_min_maj = ll_len_base(info->max_major, 10) +\
			ll_len_base(info->max_minor, 10) + 3;
		info->size = (len_min_maj > len_size ? len_min_maj : len_size);
	}
	else
		info->size = len_size;
	info->count_link = ull_len_base(info->count_link, 10);
	info->max_minor = ull_len_base(info->max_minor, 10);
	info->max_major = ull_len_base(info->max_major, 10);
	return (info);
}
