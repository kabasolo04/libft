#include "libft.h"

# define DEC "0123456789"
# define HEX_MIN "0123456789abcdef"
# define HEX_MAX "0123456789ABCDEF"
# define BUFFER_SIZE 4096

static int dec(long n, char *buf, int pos)
{
	char temp[20];
	int  i;
	int  start;

	i = 19;
	temp[i--] = '\0';
	if (n == 0)
		temp[i--] = '0';
	while (n > 0)
	{
		temp[i--] = '0' + (n % 10);
		n /= 10;
	}
	start = i + 1;
	ft_memcpy(buf + pos, temp + start, 19 - start);
	return (19 - start);
}

static int	hex(unsigned long nbr, char *base, char *buf, int pos)
{
	char	temp[16];
	int		i;
	int		j;

	i = 0;
	if (nbr == 0)
	{
		buf[pos] = base[0];
		return (1);
	}
	while (nbr > 0)
	{
		temp[i++] = base[nbr % 16];
		nbr /= 16;
	}
	j = 0;
	while (j < i)
	{
		buf[pos + j] = temp[i - 1 - j];
		j++;
	}
	return (i);
}

static int string(char *str, char *buf, int pos)
{
	int len;

	if (!str)
		return (string("(null)", buf, pos));
	len = ft_strlen(str);
	ft_memcpy(buf + pos, str, len);
	return (len);
}

static int	filter(char c, va_list va, char *buf, int pos)
{
	if (c == 'c')
	{
		buf[pos] = va_arg(va, int);
		return (1);
	}
	if (c == 's')
		return (string(va_arg(va, char *), buf, pos));
	if (c == 'p')
	{
		ft_memcpy(buf + pos, "0x", 2);
		return (2 + hex(va_arg(va, unsigned long), HEX_MIN, buf, pos + 2));
	}
	if (c == 'd' || c == 'i')
		return (dec(va_arg(va, int), buf, pos));
	if (c == 'u')
		return (dec(va_arg(va, unsigned int), buf, pos));
	if (c == 'x')
		return (hex(va_arg(va, unsigned int), HEX_MIN, buf, pos));
	if (c == 'X')
		return (hex(va_arg(va, unsigned int), HEX_MAX, buf, pos));
	buf[pos] = c;
	return (1);
}

int	ft_printf(char const *s, ...)
{
	char	buf[BUFFER_SIZE];
	int		pos;
	va_list	va;

	pos = 0;
	va_start(va, s);
	while (*s)
	{
		if (*s == '%')
			pos += filter(*++s, va, buf, pos);
		else
			buf[pos++] = *s;
		s += !(!s);
	}
	if (pos > 0)
		write(1, buf, pos);
	va_end(va);
	return (pos);
}
