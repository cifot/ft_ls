/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:24:32 by nharra            #+#    #+#             */
/*   Updated: 2019/09/05 18:53:36 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_rec(unsigned n, int fd)
{
	if (n < 10)
		ft_putchar_fd('0' + n, fd);
	else
	{
		ft_rec(n / 10, fd);
		ft_rec(n % 10, fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	long lnum;

	lnum = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		lnum = -lnum;
	}
	ft_rec(lnum, fd);
}
