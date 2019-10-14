/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:50:01 by nharra            #+#    #+#             */
/*   Updated: 2019/10/14 17:09:15 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <stdio.h>

void			hard_print(t_dlist *args, char *dirname, int print_full)
{
	t_ls_info		*info;
	struct stat		st;
	if (!stat(dirname, &st))
	{
		printf("%s total %lld\n", dirname, st.st_size);
	}
	if (!(info = init_ls_info(args)))
		return ;
	while (args)
	{
		print_type((char *)args->content);
		print_mode((char *)args->content);
		print_link_and_names((char *)args->content, info);
		print_time_and_blocks((char *)args->content, info);
		print_name_with_link((char *)args->content, print_full);
		ft_putchar('\n');
		args = args->next;
	}
	free(info);
}
