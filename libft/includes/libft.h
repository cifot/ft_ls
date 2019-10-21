/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:17:27 by nharra            #+#    #+#             */
/*   Updated: 2019/10/21 14:32:28 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# define BUFF_SIZE 1024
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*
**						MEMORY
*/

long				ft_atol(const char *nptr);
int					ft_atoi(const char *nptr);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t a);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_safe_strcat(char **dest, const char *src);
char				*ft_strtoull(unsigned long long num, unsigned base);
char				*ft_strtoll(long long num, unsigned base);
char				*ft_lltostr(long long num, unsigned base);
char				*ft_ulltostr(unsigned long long num, unsigned base);
int					ll_len_base(long long num, unsigned base);
int					ull_len_base(unsigned long long num, unsigned base);
void				ft_swap_int(int *a, int *b);
void				ft_swap_link(void **a, void **b);

/*
**						SINGLE_LINKED_LIST
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **lst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**						FILE
*/

int					get_next_line(const int fd, char **line);

/*
**						PRINTF
*/

typedef enum	e_flags {
	flag_plus = 1,
	flag_minus = 2,
	flag_space = 4,
	flag_zero = 8,
	flag_hash = 16
}				t_flags;

typedef enum	e_size_type {
	size_l,
	size_ll,
	size_h,
	size_hh,
	size_L,
	size_default
}				t_size_type;

typedef enum	e_type {
	type_u,
	type_d,
	type_i,
	type_x,
	type_X,
	type_o,
	type_f,
	type_c,
	type_p,
	type_s,
	type_percent
}				t_type;

typedef struct		s_print_info
{
	int				flags;
	int				width;
	int				precision;
	t_size_type		size_type;
	t_type			type;
}					t_print_info;

int					ft_printf(const char *format, ...);
int					putll_base(long long num, t_print_info *info);
void				put_nsym(int count, char c);
void				check_flag(t_print_info *info, const char **ptr);
int					ft_atois(const char **str);
void				check_size(t_print_info *info, const char **ptr);
int					check_type(t_print_info *info, const char **ptr);
int					parser(const char *format, va_list params);
int					putnum_base(unsigned long long num, unsigned base,
						t_print_info *info);
char				*ull_base(unsigned long long num, t_print_info *info);
char				*ll_base(long long num, t_print_info *info);
int					print_params(t_print_info *info, va_list params);
int					print_d(t_print_info *info, va_list params);
int					print_u(t_print_info *info, va_list params);
int					print_p(t_print_info *info, va_list params);
int					print_s(t_print_info *info, va_list params);
int					print_c(t_print_info *info, va_list params);
int					print_oxx(t_print_info *info, va_list params);
int					print_oxx_zero_prec(t_print_info *info);
int					print_f(t_print_info *info, va_list params);
int					print_percent(t_print_info *info);
char				*str_nsym(int count, char sym);
char				*ft_join_beg(char **s1, const char *s2);
char				*ft_join(char **s1, const char *s2);
char				*join_nsym(char **s, int flag, int count, char c);
char				*num_base(unsigned long long num, unsigned base,
							t_print_info *info);

/*
**						DOUBLE_LINKED_LIST
*/

typedef struct		s_dlist
{
	void			*content;
	int				tag;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

void				ft_dlist_delone(t_dlist **lst, t_dlist *ptr,
						void (*del)(void *));
void				ft_dlist_del(t_dlist **lst, void (*del)(void *));
t_dlist				*ft_dlist_find(t_dlist const *lst, void *data,
						int (*f)(void *, void *));
t_dlist				*ft_dlist_push(t_dlist **lst, void *data, size_t size,
						int tag);
void				ft_dlist_simple_delone(t_dlist **lst, t_dlist *ptr);
void				ft_dlist_simple_del(t_dlist **lst);
t_dlist				*ft_dlist_find_tag(t_dlist const *lst, int tag);
void				ft_dlist_delone_link(t_dlist **lst, t_dlist *ptr);
void				ft_dlist_del_link(t_dlist **lst);
t_dlist				*ft_dlist_push_link(t_dlist **lst, void *data, int tag);
t_dlist				*ft_dlist_addfront_link(t_dlist **lst, void *data,
						int tag);
void				ft_dlist_add_prev(t_dlist **lst, t_dlist *side,
						t_dlist *el);
size_t				ft_dlist_len(t_dlist *ptr);
void				ft_dlist_add_after(t_dlist *after, t_dlist *el);
t_dlist				*ft_dlist_create_el(void *el, int tag);
void				ft_dlist_sort(t_dlist *beg,
					int (*cmp)(const void *, const void *));
int					ft_dlist_is_tagsort(t_dlist *lst, int is_ascending);
t_dlist				*ft_dlist_addfront(t_dlist **lst, void *data,
					size_t size, int tag);

/*
**						QUEUE
*/

typedef struct		s_queue
{
	t_dlist			*beg;
	t_dlist			*end;
	size_t			size;
}					t_queue;

int					ft_queue_push_link(t_queue *queue, void *el, int tag);
void				ft_queque_del_link(t_queue **queue);
void				*ft_queue_pop(t_queue *queue);
t_queue				*ft_queue_new(void);

/*
**						PRIORITY_QUEUE
*/

/*
**						STACK
*/

typedef struct		s_stack
{
	t_dlist			*beg;
	size_t			size;
}					t_stack;

int					ft_stack_push_link(t_stack *stack, void *el, int tag);
void				ft_stack_del_link(t_stack **stack);
void				*ft_stack_pop(t_stack *stack);
t_stack				*ft_stack_new(void);

#endif
