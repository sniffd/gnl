/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:16:21 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 06:16:22 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	m;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	m = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			m = i;
		i++;
	}
	if (!(str = (char *)ft_memalloc(m + 2)))
		return (0);
	ft_strncpy(str, s, m + 1);
	return (str);
}
