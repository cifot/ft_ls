/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collumn_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:46:59 by nharra            #+#    #+#             */
/*   Updated: 2019/10/24 20:01:16 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_ls.h"

static unsigned		max_size(t_dlist *args)
{
	unsigned	size;
	t_dlist		*ptr;
	size_t		len;

	size = 0;
	ptr = args;
	while (ptr)
	{
		if ((len = ft_strlen(skip_dirs((char *)ptr->content))) > size)
			size = len;
		ptr = ptr->next;
	}
	return (size);
}

static unsigned		max_size_path(t_dlist *args)
{
	unsigned	size;
	t_dlist		*ptr;
	size_t		len;

	size = 0;
	ptr = args;
	while (ptr)
	{
		if ((len = ft_strlen((char *)ptr->content)) > size)
			size = len;
		ptr = ptr->next;
	}
	return (size);
}

static void			print_full_path(char *str, unsigned wd)
{
	print_filename(str, 1);
	put_nsym(wd - ft_strlen(skip_dirs(str)), ' ');
}

static void			print_names(t_dlist *args, int print_full, unsigned rows,
					unsigned wd)
{
	t_dlist		*ptr;
	unsigned	i;
	unsigned	rows_copy;

	rows_copy = rows;
	while (rows--)
	{
		ptr = args;
		while (ptr)
		{
			if (print_full)
			{
				ft_putstr((char *)ptr->content);
				put_nsym(wd - ft_strlen((char *)ptr->content), ' ');
			}
			else
				print_full_path((char *)ptr->content, wd);
			i = 0;
			while (i++ < rows_copy && ptr)
				ptr = ptr->next;
		}
		ft_putchar('\n');
		args = args->next;
	}
}

void				column_print(t_dlist *args, int print_full)
{
	struct winsize	w;
	unsigned		col;
	unsigned		col_width;
	size_t			size_list;
	unsigned		rows;

	size_list = ft_dlist_len(args);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (print_full)
		col_width = max_size_path(args);
	else
		col_width = max_size(args);
	col = w.ws_col / col_width;
	rows = size_list / col + (size_list % col ? 1 : 0);
	print_names(args, print_full, rows, col_width + 1);
}
