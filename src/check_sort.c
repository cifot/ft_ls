/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:39:13 by nharra            #+#    #+#             */
/*   Updated: 2019/10/10 12:07:53 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

static void		skip_invalid(t_dlist *lst, t_dlist **ptr)
{
	struct stat		info;

	while (lst && (stat((char *)lst->content, &info) == -1))
		lst = lst->next;
	*ptr = lst;
}

static int		sort_error_files(const void *s1, const void *s2)
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
		return (ft_strcmp(s1, s2));
	else if (ret_1 == -1)
		return (-1);
	else
		return (1);
}

int				check_sort(t_dlist *ls_args, int flags)
{
	t_dlist *ptr;

	ft_dlist_sort(ls_args, sort_error_files);
	flags = flags - flags;
	skip_invalid(ls_args, &ptr);
	if (!ptr)
		return (0);
	if (flags & flag_t)
		ft_dlist_sort(ls_args, sort_error_files);
	else if (flags & flag_r)
		ft_dlist_sort(ls_args, );
	else
		ft_dlist_sort(*ls_args, )
	*/
	return (1);
}
