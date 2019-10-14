/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:41:54 by nharra            #+#    #+#             */
/*   Updated: 2019/10/14 15:06:05 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

void		print_filename(char *str)
{
	char *end;

	while (*str)
		++str;
	end = str;
	while (*str != '/')
		--str;
	write(1, str + 1, end - str);
}

void		simple_print(t_dlist *args)
{
	while (args)
	{
		print_filename((char *)args->content);
		ft_putchar('\n');
		args = args->next;
	}
}
