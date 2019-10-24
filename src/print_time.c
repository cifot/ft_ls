/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:46:55 by nharra            #+#    #+#             */
/*   Updated: 2019/10/24 16:42:31 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>

static void		print_10000(char *str, size_t len)
{
	write(1, str + 4, len - 23);
	write(1, " 10000 ", 6);
}

void			print_time(const char *filename)
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
	if (st.st_mtimespec.tv_sec > 253234080000)
		print_10000(str, len);
	else if (st.st_mtimespec.tv_sec - current_time > 3600 ||
	current_time - st.st_mtimespec.tv_sec > 15724800)
	{
		write(1, str + 4, len - 18);
		ft_putchar(' ');
		write(1, str + len - 5, 4);
	}
	else
		write(1, str + 4, len - 13);
	write(1, " ", 1);
}
