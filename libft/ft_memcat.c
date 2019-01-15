#include "libft.h"

char	*ft_memcat(void *s1, const void *s2, size_t l1, size_t l2)
{
	ft_memcpy((s1 + l1), s2, l2);
	return (s1);
}