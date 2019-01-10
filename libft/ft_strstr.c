/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:27:01 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 06:27:01 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		f;
	size_t	len;

	f = 0;
	len = ft_strlen(needle);
	if (needle[0] == 0)
		return ((char *)haystack);
	while ((haystack = ft_strchr((haystack), needle[0])))
	{
		f = 1;
		while (len--)
		{
			if (haystack[len] != needle[len])
			{
				f = 0;
				haystack++;
				break ;
			}
		}
		if (f == 1)
			return ((char *)haystack);
		len = ft_strlen(needle);
	}
	return (0);
}
