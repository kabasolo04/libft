#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	b;
	int	n;

	i = 0;
	n = 0;

	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i ++;

	b = 1 - 2*(str[i] == '-');
	i += (str[i] == '-' || str[i] == '+');

	while (str[i] && ft_isdigit(str[i]))
		n = (n * 10) + str[i++] - '0';

	return (n * b);
}
