/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:59:51 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 08:59:51 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long long num)
{
	int	i;

	i = 1;
	if (num == 0)
		return (1);
	num = ft_abs(num);
	while (num >= 10)
	{
		num = num / 10;
		i++;
	}
	return (i);
}
