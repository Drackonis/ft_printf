#include "ft_printf.h"

void	ft_printf_int(t_printf p)
{	int d;
	d = va_arg(p.arg, int);
	ft_putnbr(d);		
}

t_printf	percent_found(t_printf p)
{
	//ft_putchar('>');
	ft_printf_int(p);
	//ft_putchar(p.format[p.i]);
	//ft_putstr("->");
	p.i += 2;
	return (p);
}

int		check_error(t_printf p)
{
	p.i = 0;
	return (p.i);
}

int		ft_printf(const char *format, ...)
{
	t_printf p;

	p.i = 0;
	p.format = ft_strdup(format);
	printf ("Len : %d\n", ft_strlen(p.format));
	check_error(p);
	va_start(p.arg, format);
	while (p.format[p.i])
	{
		if (p.format[p.i] == '%')
		{
			p = percent_found(p);
		}
		else
		{
			write(1, &p.format[p.i], 1);
			p.i++;
		}
	}
	va_end(p.arg);
	ft_putchar('\n');
	return (p.i);
}

int		main(int argc, char **argv)
{
	argc++;
	int	x;
	x = ft_printf(argv[1], ft_atoi(argv[2]));
	printf ("X = %d", x);
	return (0);
}
