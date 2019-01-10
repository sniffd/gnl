/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:37:31 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 08:37:31 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchtrim(char const *s, char c)
{
	size_t	i;
	size_t	m;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	m = 0;
	while (*s == c)
		s++;
	while (s[i])
	{
		if (s[i] != c)
			m = i;
		i++;
	}
	if (!(str = (char *)ft_memalloc(m + 2)))
		return (0);
	ft_strncpy(str, s, m + 1);
	return (str);
}
