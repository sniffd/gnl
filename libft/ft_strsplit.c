/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 05:24:00 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 05:24:01 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_floop(char const *s, char c, int i, int *n)
{
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			(*(n))++;
		}
		i++;
	}
}

static int	ft_free(char **ar, int n)
{
	while (n >= 0)
	{
		ft_strdel(&(ar[n]));
		n--;
	}
	free(ar);
	return (-1);
}

static void	ft_null(size_t *len, size_t *lens, int *i)
{
	*len = 0;
	*lens = 0;
	*i = 0;
}

static int	ft_sloop(char const *s, char c, int n, char **ar)
{
	size_t	len;
	size_t	lens;
	int		i;

	ft_null(&len, &lens, &i);
	while (s[i] != '\0')
	{
		if (s[i] && s[i] != c)
		{
			len = ft_strchlen((s + i), c);
			i += len;
			if (!(ar[n] = (char *)ft_memalloc(len + 1)))
				return (ft_free(ar, n));
			ar[n][len] = '\0';
			lens = len;
			while (len--)
				ar[n][len] = s[i - lens + len];
			len = 0;
			n++;
		}
		if (s[i])
			i++;
	}
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	int		n;
	int		i;
	char	**ar;

	if (!s)
		return (0);
	n = 0;
	i = 0;
	ft_floop(s, c, i, &n);
	if (!(ar = (char **)ft_memalloc(sizeof(char *) * (n + 1))))
		return (0);
	ar[n] = 0;
	n = 0;
	if (ft_sloop(s, c, n, ar) == -1)
		ar = 0;
	return (ar);
}
