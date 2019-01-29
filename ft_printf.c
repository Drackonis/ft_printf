#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{	
	va_list arg;
	int	i;
	int	d;

	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			d = va_arg(arg, int);
			ft_putnbr(d);
			i++;
		}
		else			
			ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (0);	
}

int	main()
{
	ft_printf("Jusqu'ici tout vas bien ! %d", 123456789);
	return (0);
}
