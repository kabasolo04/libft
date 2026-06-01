#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len);
	return (str);
}