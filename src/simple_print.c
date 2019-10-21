/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:41:54 by nharra            #+#    #+#             */
/*   Updated: 2019/10/21 18:55:12 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		simple_print(t_dlist *args, int print_full)
{
	while (args)
	{
		if (print_full)
			print_filename((char *)args->content);
		else
			print_filename((char *)args->content);
		ft_putchar('\n');
		args = args->next;
	}
}
