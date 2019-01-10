/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:15:58 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 06:15:59 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		nb;
	int		i;
	char	*res;

	nb = n;
	i = 1;
	while ((nb = nb / 10))
		i++;
	i = n < 0 ? ++i : i;
	i = n == 0 ? 1 : i;
	if (!(res = (char *)ft_memalloc(i + 1)))
		return (0);
	if (n < 0)
		res[0] = '-';
	res[i--] = '\0';
	nb = n;
	if (n == 0)
		res[0] = '0';
	while (nb != 0)
	{
		res[i--] = ft_abs(nb % 10) + '0';
		nb = nb / 10;
	}
	return (res);
}
