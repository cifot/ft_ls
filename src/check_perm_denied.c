/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_perm_denied.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:30:20 by nharra            #+#    #+#             */
/*   Updated: 2019/10/25 17:38:08 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <dirent.h>

int		check_perm_denied(const char *dirname)
{
	DIR		*dir;

	if (!(dir = opendir(dirname)))
	{
		ft_putstr_fd("ls: ", 2);
		print_filename(dirname, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (1);
	}
	closedir(dir);
	return (0);
}
