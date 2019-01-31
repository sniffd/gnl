/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:51:10 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/01/31 22:51:10 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memfjoin(void **s1, const void *s2, size_t l1, size_t l2)
{
	char	*str;

	if (!s1 || !s2 || !(str = ft_memalloc(l1 + l2)))
		return (0);
	ft_memcpy(str, *s1, l1);
	ft_memcat(str, s2, l1, l2);
	free(*s1);
	return (str);
}
