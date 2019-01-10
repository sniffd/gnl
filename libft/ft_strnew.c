/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:21:57 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 06:21:57 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	max;

	max = -1;
	if (size == max)
		return (0);
	if ((str = (char *)ft_memalloc(size + 1)))
		str[size] = '\0';
	return (str);
}
