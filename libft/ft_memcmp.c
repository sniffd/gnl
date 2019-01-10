/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 05:25:11 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 05:25:12 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	int				res;

	i = 0;
	res = 0;
	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (str1[0] == 0 || str2[0] == 0)
		res = str1[0] - str2[0];
	while (i < n)
	{
		res = str1[i] - str2[i];
		if (res != 0)
			break ;
		i++;
	}
	return (res);
}
