/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:48:09 by nharra            #+#    #+#             */
/*   Updated: 2019/10/10 15:22:30 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS
# include "libft.h"

typedef enum	e_lsflags {
	flag_R = 1 << 0,
	flag_a = 1 << 1,
	flag_r = 1 << 2,
	flag_l = 1 << 3,
	flag_t = 1 << 4,
}				t_lsflags;

int			make_flag_and_args(char **argv, int *flags, t_dlist **ls_args);
void		check_sort(t_dlist *ls_args, int flags);
long		cmp_error(const void *s1, const void *s2);
long		cmp_time_ascending(const void *s1, const void *s2);
long		cmp_time_descending(const void *s1, const void *s2);
long		void_strcmp(const void *s1, const void *s2);
long		void_revstrcmp(const void *s1, const void *s2);



# endif
