/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_len_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:44:04 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 10:51:40 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ll_len_base(long long num, unsigned base)
{
	unsigned long long	u_num;

	u_num = num;
	if (num >= 0)
	{
		return (ull_len_base(u_num, base));
	}
	else
	{
		u_num = -u_num;
		return (ull_len_base(u_num, base));
	}
}
