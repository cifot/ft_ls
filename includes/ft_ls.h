/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:48:09 by nharra            #+#    #+#             */
/*   Updated: 2019/10/25 20:39:56 by nharra           ###   ########.fr       */
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
	flag_S = 1 << 5,
	flag_1 = 1 << 6,
	flag_c = 1 << 7,
	flag_d = 1 << 8
}				t_lsflags;

typedef struct	s_ls_info
{
	size_t		count_link;
	size_t		len_username;
	size_t		len_group;
	long long	size;
	int			max_major;
	int			max_minor;
}				t_ls_info;

int				make_flag_and_args(char **argv, int *flags,
					t_dlist **ls_args, t_dlist *error);
void			check_sort(t_dlist *ls_args, int flags);
int				cmp_ctime_ascending(const void *s1, const void *s2);
int				cmp_ctime_descending(const void *s1, const void *s2);
int				cmp_mtime_ascending(const void *s1, const void *s2);
int				cmp_mtime_descending(const void *s1, const void *s2);
int				void_strcmp(const void *s1, const void *s2);
int				void_revstrcmp(const void *s1, const void *s2);
int				cmp_size_ascending(const void *s1, const void *s2);
int				cmp_size_descending(const void *s1, const void *s2);
t_ls_info		*init_ls_info(t_dlist *args);
void			ls_dir(char *dirname, int flags, int write_name,
				t_dlist *args);
void			simple_print(t_dlist *args, int print_full);
void			hard_print(t_dlist *args, int print_path, int flags);
void			column_print(t_dlist *args, int print_full);
t_dlist			*erase_dirs(t_dlist **lst, int flags);
int				find_dir(const void *s1, const void *s2);
void			print_mode(const char *filename);
void			print_link_and_names(const char *filename, t_ls_info *info);
void			print_blocks(const char *filename, t_ls_info *info);
void			print_filename(const char *str, int fd);
void			print_name_with_link(const char *filename, int print_full);
char			get_extatr(const char *filename);
void			print_total(t_dlist *args);
int				check_perm_denied(const char *dirname);
void			print_mtime(const char *filename);
void			print_ctime(const char *filename);
int				print_illegal_option(char c);
char			*skip_dirs(char *str);

#endif
