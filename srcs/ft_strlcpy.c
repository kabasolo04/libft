#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);

	if (dstsize == 0)
		return (len);

	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i ++;
	}

	dst[i] = '\0';

	return (len);
}
