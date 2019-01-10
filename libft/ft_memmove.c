/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:31:29 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 06:31:29 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dststr;
	unsigned char	*srcstr;

	dststr = dst;
	srcstr = (unsigned char *)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
	{
		while (len)
		{
			dststr[len - 1] = srcstr[len - 1];
			len--;
		}
	}
	return (dst);
}
