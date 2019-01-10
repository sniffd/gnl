/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 05:24:30 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 05:24:31 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pres(const char *str)
{
	long long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (((res * 10 + (*str - '0'))) / 10 != res)
			return (-1);
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)res);
}

static int	ft_mres(const char *str)
{
	long long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (((res * 10 + (*str - '0'))) / 10 != res)
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)-res);
}

int			ft_atoi(const char *str)
{
	int			f;

	f = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			f = 1;
		str++;
	}
	if (f)
		return (ft_mres(str));
	else
		return (ft_pres(str));
}
