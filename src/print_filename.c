/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:52:59 by nharra            #+#    #+#             */
/*   Updated: 2019/10/22 15:36:29 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

void		print_filename(const char *path, int fd)
{
	const char *end;
	const char *ptr;

	ptr = path;
	while (*ptr)
		++ptr;
	end = ptr;
	while (*ptr != '/' && ptr != path)
		--ptr;
	if (ptr != path)
		++ptr;
	write(fd, ptr, end - ptr);
}
