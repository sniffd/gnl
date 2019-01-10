#include "libft.h"

char	*ft_memrchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*((char *)s + n) == c)
			return ((char *)s + n);
		n--;
	}
	return (0);
}