/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_illegal_option.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:51:40 by nharra            #+#    #+#             */
/*   Updated: 2019/10/24 16:39:39 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	print_illegal_option(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]", 2);
	ft_putstr_fd(" [file ...]\n", 2);
}
