#include "libft.h"

int	ft_toupper(int c)
{
	return (c - 32 * (c >= 'a' && c <= 'z'));
}
