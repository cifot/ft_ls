/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_dirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:36:22 by nharra            #+#    #+#             */
/*   Updated: 2019/10/24 16:37:12 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

t_dlist			*erase_dirs(t_dlist **lst)
{
	t_dlist			*dirs;
	t_dlist			*ptr;
	t_dlist			*next;
	struct stat		st;

	ptr = *lst;
	dirs = NULL;
	while (ptr)
	{
		stat((char *)ptr->content, &st);
		if ((st.st_mode & S_IFMT) == S_IFDIR)
		{
			next = ptr->next;
			ft_dlist_push_link(&dirs, ptr->content, ptr->tag);
			ft_dlist_delone_link(lst, ptr);
			ptr = next;
		}
		else
			ptr = ptr->next;
	}
	return (dirs);
}
