/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info_folder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:43:16 by nharra            #+#    #+#             */
/*   Updated: 2019/10/10 16:16:47 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>


void	print_info_folder(const char *filename, int flags)
{
	DIR				*dir;
	struct dirent	*cur_dir;

	if (!(dir = opendir(filename)))
		ft_printf("ls: %s: Permission denied\n");
	while ((cur_dir = readdir(dir)))
	{
		if (flags & flag_l)
			print_info_object(cur_dir);
		else
			ft_printf("%s\n", cur_dir->d_name);
	}
}
