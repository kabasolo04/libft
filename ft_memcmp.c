#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	i = 0;

	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	
	return (0);
}
