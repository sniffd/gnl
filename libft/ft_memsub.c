#include "libft.h"

void	*ft_memsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || !(str = (char *)ft_memalloc(len)))
		return (0);
	while (len)
	{
		str[len] = s[start + len];
		len--;
		if (!len)
		{
			str[len] = s[start + len];
			break ;
		}
	}
	return ((void *)str);
}