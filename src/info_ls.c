/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:59:13 by nharra            #+#    #+#             */
/*   Updated: 2019/10/11 16:37:21 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>

t_ls_info			*new_ls_info(void)
{
	t_ls_info	*info;

	if (!(info = (t_ls_info *)malloc(sizeof(*info))))
		return (NULL);
	info->len_count_link = 0;
	info->len_size = 0;
	info->len_username = 0;
	return (info);
}

static void			check_file(t_ls_info *ls_info, struct dirent *info, int flags)
{
	struct passwd	*psw;
	struct stat		st;

	if (!((flags & flag_a) && info->d_name[0] == '.'))
		return ;
	if (stat(info->d_name, &st))
		return ;
	if (st.st_nlink > ls_info->len_count_link)
		ls_info->len_count_link = st.st_nlink;
	psw = getpwuid(st.st_uid);
	if (ft_strlen(psw->pw_name) > ls_info->len_username)
		ls_info->len_username = ft_strlen(psw->pw_name);
	if (st.st_size > ls_info->len_size)
		ls_info->len_size = st.st_size;
}

t_ls_info			*init_ls_info(const char *dirname, int flags)
{
	DIR				*dir;
	struct dirent	*info;
	t_ls_info		*ls_info;

	if (!(dir = opendir(dirname)))
		return (NULL);
	ls_info = new_ls_info();
	while (info = readdir(dir))
		check_file(ls_info, info, flags);
	closedir(dir);
	ls_info->len_count_link = ll_len_base(ls_info->len_count_link, 10);
	ls_info->len_size = ll_len_base(ls_info->len_size, 10);
}
