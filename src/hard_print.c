/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:50:01 by nharra            #+#    #+#             */
/*   Updated: 2019/10/22 18:14:09 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

void			hard_print(t_dlist *args, int print_path)
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
		print_time((char *)args->content);
		print_name_with_link((char *)args->content, !print_path);
		ft_putchar('\n');
		args = args->next;
	}
	free(info);
}
