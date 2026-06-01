#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(count * size);

	if (!str)
		return NULL;

	while ((i < count * size))
		str[i++] = 0;
	
	return (str);
}
