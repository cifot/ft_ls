/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:48:09 by nharra            #+#    #+#             */
/*   Updated: 2019/10/11 16:30:34 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"

typedef enum	e_lsflags {
	flag_R = 1 << 0,
	flag_a = 1 << 1,
	flag_r = 1 << 2,
	flag_l = 1 << 3,
	flag_t = 1 << 4,
}				t_lsflags;

typedef struct	s_ls_info
{
	int		len_count_link;
	int		len_username;
	int		len_size;
}				t_ls_info;

int				make_flag_and_args(char **argv, int *flags, t_dlist **ls_args);
void			check_sort(t_dlist *ls_args, int flags);
long			cmp_time_ascending(const void *s1, const void *s2);
long			cmp_time_descending(const void *s1, const void *s2);
long			void_strcmp(const void *s1, const void *s2);
long			void_revstrcmp(const void *s1, const void *s2);
t_ls_info		*new_ls_info(void);
t_ls_info		*init_ls_info(const char *dirname, int flags);
void			ls_dir(char *dirname, int flags, int write_name,
						t_dlist *args);
void			simple_print(t_dlist *args);
t_dlist			*erase_dirs(t_dlist **lst);

#endif
