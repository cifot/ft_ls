/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:50:01 by nharra            #+#    #+#             */
/*   Updated: 2019/10/25 17:15:17 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

void			hard_print(t_dlist *args, int print_path, int flags)
{
	t_ls_info		*info;

	if (!print_path && args)
		print_total(args);
	if (!(info = init_ls_info(args)))
		return ;
	while (args)
	{
		print_mode((char *)args->content);
		print_link_and_names((char *)args->content, info);
		print_blocks((char *)args->content, info);
		if (flags & flag_c)
			print_ctime((char *)args->content);
		else
			print_mtime((char *)args->content);
		print_name_with_link((char *)args->content, !print_path);
		ft_putchar('\n');
		args = args->next;
	}
	free(info);
}
