/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 05:26:06 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 05:26:06 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_loop(size_t l, int *f, const char **haystack, const char *needle)
{
	while (l--)
	{
		if ((*(haystack))[l] != needle[l])
		{
			*f = 0;
			(*(haystack))++;
			break ;
		}
	}
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int				f;
	size_t			l;
	const char		*check;

	f = 0;
	l = ft_strlen(needle);
	if (len > ft_strlen(haystack))
		check = haystack + ft_strlen(haystack);
	else
		check = haystack + len;
	if (needle[0] == 0)
		return ((char *)haystack);
	while ((haystack = ft_strchr((haystack), needle[0])))
	{
		if (haystack > check)
			break ;
		f = 1;
		ft_loop(l, &f, &haystack, needle);
		l = ft_strlen(needle);
		if ((haystack + l) > check)
			break ;
		if (f == 1)
			return ((char *)haystack);
	}
	return (0);
}
