/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:44:01 by nharra            #+#    #+#             */
/*   Updated: 2019/10/22 16:39:07 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

void	print_total(t_dlist *args)
{
	struct stat		st;
	long			count;

	count = 0;
	while(args)
	{
		if (lstat((char *)args->content, &st))
			if (stat((char *)args->content, &st))
			{
				args = args->next;
				continue;
			}
		count += st.st_blocks;
		args = args->next;
	}
	ft_printf("total %ld\n", count);
}
