/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:48:09 by nharra            #+#    #+#             */
/*   Updated: 2019/10/21 18:19:58 by nharra           ###   ########.fr       */
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
	size_t		count_link;
	size_t		len_username;
	size_t		len_group;
	long long	size;
}				t_ls_info;

int				make_flag_and_args(char **argv, int *flags,
					t_dlist **ls_args, t_dlist *error);
void			check_sort(t_dlist *ls_args, int flags);
int				cmp_time_ascending(const void *s1, const void *s2);
int				cmp_time_descending(const void *s1, const void *s2);
int				void_strcmp(const void *s1, const void *s2);
int				void_revstrcmp(const void *s1, const void *s2);
t_ls_info		*init_ls_info(t_dlist *args);
void			ls_dir(char *dirname, int flags, int write_name,
						t_dlist *args);
void			simple_print(t_dlist *args, int print_full);
void			hard_print(t_dlist *args, char *dirname, int print_full);
t_dlist			*erase_dirs(t_dlist **lst);
int				find_dir(const void *s1, const void *s2);
void			print_type(const char *filename);
void			print_mode(const char *filename);
void			print_link_and_names(const char *filename, t_ls_info *info);
void			print_time_and_blocks(const char *filename, t_ls_info *info);
void			print_filename(const char *str);
void			print_name_with_link(const char *filename, int print_full);
char			get_extatr(const char *filename);

#endif
