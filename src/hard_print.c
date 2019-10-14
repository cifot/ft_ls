/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:50:01 by nharra            #+#    #+#             */
/*   Updated: 2019/10/14 15:33:52 by nharra           ###   ########.fr       */
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

void			hard_print(t_dlist *args)
{
	t_ls_info		*info;

	if (!(info = init_ls_info(args)))
		return ;
	while (args)
	{
		print_type((char *)args->content);
		print_mode((char *)args->content);
		print_link_and_names((char *)args->content, info);
		print_time((char *)args->content);
		print_name((char *)args->content);
		ft_putchar('\n');
		args = args->next;
	}
}
