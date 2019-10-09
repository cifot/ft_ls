/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:18:10 by nharra            #+#    #+#             */
/*   Updated: 2019/09/16 14:46:45 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		make_str(char *str, char **line, char **find_chr)
{
	*find_chr = ft_strchr(str, '\n');
	if (*find_chr)
		**find_chr = '\0';
	if (!ft_safe_strcat(line, str))
		return (-1);
	return (0);
}

static int		clean_line(char **str, int ret_value)
{
	ft_memdel((void **)str);
	return (ret_value);
}

static int		ft_read_from_fd(t_dlist **lst, const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		res;
	char	*find_chr;
	int		flag;

	find_chr = NULL;
	flag = 0;
	while ((res = read(fd, buf, BUFF_SIZE)))
	{
		flag = 1;
		if (res == -1)
			return (-1);
		buf[res] = '\0';
		if (make_str(buf, line, &find_chr))
			return (-1);
		if (find_chr)
		{
			if (find_chr[1] != '\0')
				if (!ft_dlist_push(lst, find_chr + 1,
					ft_strlen(find_chr + 1) + 1, fd))
					return (-1);
			break ;
		}
	}
	return (flag == 0 ? clean_line(line, 0) : 1);
}

static int		ft_read_from_lst(t_dlist **lst, t_dlist *ptr, char **line)
{
	char	*find_chr;
	char	*new;

	find_chr = NULL;
	if (make_str((char *)ptr->content, line, &find_chr))
		return (clean_line(line, -1));
	if (find_chr == NULL || find_chr[1] == '\0')
	{
		ft_dlist_simple_delone(lst, ptr);
		return (find_chr == NULL ? clean_line(line, 0) : 1);
	}
	else
	{
		if (!(new = (char *)malloc(ft_strlen(find_chr + 1) + 1)))
			return (clean_line(line, -1));
		ft_strcpy(new, find_chr + 1);
		free(ptr->content);
		ptr->content = new;
		return (1);
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_dlist	*lst;
	t_dlist			*current;
	int				res;

	if (!line || !(*line = ft_memalloc(1)))
		return (-1);
	current = ft_dlist_find_tag(lst, fd);
	if (current)
	{
		if ((res = ft_read_from_lst(&lst, current, line)) == -1)
			return (clean_line(line, -1));
		if (res == 0)
		{
			return ((ft_read_from_fd(&lst, fd, line) == -1) ?
					-1 : 1);
		}
		else
			return (1);
	}
	else
	{
		return (ft_read_from_fd(&lst, fd, line));
	}
}
