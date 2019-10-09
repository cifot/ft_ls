/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ull_len_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:45:28 by nharra            #+#    #+#             */
/*   Updated: 2019/10/07 20:52:37 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ull_len_base(unsigned long long num, unsigned base)
{
	int count;

	count = 0;
	if (base < 2 || base > 16)
		return (0);
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		++count;
	}
	return (count);
}
