/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:28:01 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 06:28:01 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lend;
	size_t	lens;
	size_t	s;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (size == 0 || lend > (size - 1))
		s = 0;
	else
		s = (size - 1) - lend;
	ft_strncat(dst, src, s);
	if (size >= lend + lens || lens + lend <= lens + size)
		return (lens + lend);
	else
		return (lens + size);
}
