/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:39:13 by nharra            #+#    #+#             */
/*   Updated: 2019/10/09 19:07:21 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int		sort_error_files(void *s1, void *s2)
{
	struct stat		info;
	char			*str1;
	char			*str2;
	int				ret_1;
	int				ret_2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	ret_1 = stat(str1, &info);
	ret_2 = stat(str2, &info);
	if (ret_1 == ret_2)
		return (0);
	else if (ret_1 == -1)
		return (-1);
	else if (ret_2 == -1)
		return (1);
}

int		check_sort(t_dlist **ls_args, int flags)
{
	t_dlist *ptr;

	ft_dlist_sort(*ls_args, sort_error_files);
	ptr = *ls_args;
	while(ptr || ptr->content)
	if (flags & flag_t)
		ft_dlist_sort(*ls_args, )
	else if (flags & flag_r)
		ft_dlist_sort(*ls_args, )
	else
		ft_dlist_sort(*ls_args, )
}
