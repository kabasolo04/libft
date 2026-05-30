#include "libft.h"

# define DEC "0123456789"
# define HEX_MIN "0123456789abcdef"
# define HEX_MAX "0123456789ABCDEF"

static int	dec(long nbr)
{
	if (nbr < 0)
		return (write(1, "-", 1) + dec(-nbr));
	if (nbr > 9)
		return (dec(nbr / 10) + write(1, &DEC[nbr % 10], 1));
	return (write(1, &DEC[nbr % 10], 1));
}

static int	hex(unsigned long nbr, char *base)
{
	if (nbr > 15)
		return (hex(nbr / 16, base) + write(1, &base[nbr % 16], 1));
	return (write(1, &base[nbr % 16], 1));
}

static int	string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (string("(null)"));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

static int	filter(char c, va_list va)
{
	if (c == 'c')
		return (write(1, &(char){va_arg(va, int)}, 1));
	if (c == 's')
		return (string(va_arg(va, char *)));
	if (c == 'p')
		return (write(1, "0x", 2) + hex(va_arg(va, unsigned long), HEX_MIN));
	if (c == 'd' || c == 'i')
		return (dec(va_arg(va, int)));
	if (c == 'u')
		return (dec(va_arg(va, unsigned int)));
	if (c == 'x')
		return (hex(va_arg(va, unsigned int), HEX_MIN));
	if (c == 'X')
		return (hex(va_arg(va, unsigned int), HEX_MAX));
	return (write(1, &c, 1));
}

int	ft_printf(char const *s, ...)
{
	int		n;
	va_list	va;

	n = 0;
	va_start(va, s);
	while (*s)
	{
		if (*s == '%')
			n += filter(*++s, va);
		else
			n += write(1, s, 1);
		s += !(!s);
	}
	return (va_end(va), n);
}
