/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perm_denied.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:30:20 by nharra            #+#    #+#             */
/*   Updated: 2019/10/24 15:26:47 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	print_perm_denied(const char *dirname)
{
	ft_putstr_fd("ls: ", 2);
	print_filename(dirname, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}
