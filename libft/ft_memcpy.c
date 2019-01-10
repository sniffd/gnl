/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:32:16 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 06:32:17 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*srcstr;
	unsigned char	*dststr;

	i = 0;
	srcstr = (unsigned char *)src;
	dststr = dst;
	if (src != dst)
	{
		while (i < n)
		{
			dststr[i] = srcstr[i];
			i++;
		}
		dst = dststr;
	}
	return (dst);
}
