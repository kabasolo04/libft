#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		write(fd, "(null)", 6);
	else
		write(fd, s, ft_strlen(s));
}
