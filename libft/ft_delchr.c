/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:37:14 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 08:37:15 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nul(size_t *i, size_t *size)
{
	*i = 0;
	*size = 0;
}

char		*ft_delchr(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	*str;

	ft_nul(&i, &size);
	while (s[i])
	{
		if (s[i] != c)
			size++;
		i++;
	}
	if (!(str = ft_memalloc(size + 1)))
		return (0);
	ft_nul(&i, &size);
	while (s[i])
	{
		if (s[i] != c)
			str[size++] = s[i];
		i++;
	}
	return (str);
}
