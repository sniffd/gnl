/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:31:55 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 06:31:55 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*srcstr;
	unsigned char	*dststr;

	i = 0;
	srcstr = (unsigned char *)src;
	dststr = dst;
	while (i < n)
	{
		dststr[i] = srcstr[i];
		if (srcstr[i] == (unsigned char)c)
			break ;
		i++;
	}
	if (i < n)
		dst = (dststr + i + 1);
	else
		dst = 0;
	return (dst);
}
