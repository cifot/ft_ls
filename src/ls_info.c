/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:55:04 by nharra            #+#    #+#             */
/*   Updated: 2019/10/22 18:44:05 by nharra           ###   ########.fr       */
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
	return (info);
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
	if (st.st_size > info->size)
		info->size = st.st_size;
	if ((len = ft_strlen(gr->gr_name)) > info->len_group)
		info->len_group = len;
	if ((len = ft_strlen(user->pw_name)) > info->len_username)
		info->len_username = len;
}

t_ls_info		*init_ls_info(t_dlist *args)
{
	t_ls_info		*info;

	if (!(info = new_ls_info()))
		return (NULL);
	while (args)
	{
		check_file((char *)args->content, info);
		args = args->next;
	}
	return (info);
}
