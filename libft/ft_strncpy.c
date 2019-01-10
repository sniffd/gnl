/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:29:29 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 06:29:30 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	ls;

	ls = ft_strlen(src);
	ft_memccpy(dst, src, 0, len);
	if (ls < len)
		ft_memset((dst + ls), 0, (len - ls));
	return (dst);
}
