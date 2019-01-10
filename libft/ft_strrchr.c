/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 05:37:16 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 05:37:17 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = "test";
	if (c == 0)
		return (ft_strchr(s, c));
	while (1)
	{
		if (i == 0)
		{
			str = ft_strchr(s, c);
			i++;
		}
		else
			str = ft_strchr((str + 1), c);
		if (str == 0 || ft_strchr(str + 1, c) == 0)
			return (str);
	}
}
