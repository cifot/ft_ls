/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:46:55 by nharra            #+#    #+#             */
/*   Updated: 2019/10/22 18:54:02 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>


void		print_time(const char *filename)
{
	struct stat		st;
	char			*str;
	time_t			current_time;
	size_t			len;

	current_time = time(NULL);
	if (lstat(filename, &st))
		if (stat(filename, &st))
			return ;
	if (!(str = ctime(&st.st_mtimespec.tv_sec)))
		return ;
	len = ft_strlen(str);
	if (st.st_mtimespec.tv_sec - current_time > 3600)
	{
		write(1, str + 4, len - 18);
		write(1, str + len - 5, 4);
		ft_putchar(' ');
	}
	else
		write(1, str + 4, ft_strlen(str) - 13);
	write(1, " ", 1);
}
