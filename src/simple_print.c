/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:41:54 by nharra            #+#    #+#             */
/*   Updated: 2019/10/12 11:18:35 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

void		simple_print(t_dlist *args)
{
	char *str;

	while (args)
	{
		str = (char *)args->content;
		while (*str)
			++str;
		while (*str != '/')
			--str;
		ft_printf("%s\n", str + 1);
		args = args->next;
	}
}
