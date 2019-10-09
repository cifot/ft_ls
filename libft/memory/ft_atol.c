/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:52:40 by czena             #+#    #+#             */
/*   Updated: 2019/09/28 14:23:37 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long		ft_check_int(char *str, int n, long res)
{
	while (n >= 0)
	{
		if (n + '0' == *str)
			res = res * 10 + n;
		n--;
	}
	return (res);
}

static int		ft_check_long(long res, char c, long sign)
{
	if (res * sign <= -922337203685477580 && c - '0' >= 8)
		return (0);
	if (res * sign >= 922337203685477580 && c - '0' >= 7)
		return (-1);
	return (1);
}

static char		*ft_start(char *nptr, long *sign)
{
	while ((*nptr >= 2 && *nptr <= 32) && *nptr != 27)
		nptr++;
	if (*nptr == '-')
		*sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	return (nptr);
}

long			ft_atol(const char *nptr)
{
	long n;
	long res;
	long sign;

	n = 9;
	res = 0;
	sign = 1;
	nptr = ft_start((char*)nptr, &sign);
	while (*nptr != '\0')
	{
		if (*nptr >= '0' && *nptr <= '9')
		{
			if (ft_check_long(res, nptr[0], sign) > 0)
				res = ft_check_int((char*)nptr, n, res);
			else
				return (ft_check_long(res, nptr[0], sign));
		}
		else
			return (res * sign);
		n = 9;
		nptr++;
	}
	return (res * sign);
}
