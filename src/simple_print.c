/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:41:54 by nharra            #+#    #+#             */
/*   Updated: 2019/10/22 16:05:39 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		simple_print(t_dlist *args, int print_full)
{
	while (args)
	{
		if (print_full)
			ft_putstr((char *)args->content);
		else
			print_filename((char *)args->content, 1);
		ft_putchar('\n');
		args = args->next;
	}
}
