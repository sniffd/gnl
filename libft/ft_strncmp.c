/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:26:18 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 06:26:18 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (n == 0)
		return (0);
	if (len2 >= n && len1 >= n)
		return (ft_memcmp(s1, s2, n));
	else
	{
		if (len1 > len2)
			return (ft_memcmp(s1, s2, len2 + 1));
		else
			return (ft_memcmp(s1, s2, len1 + 1));
	}
}
