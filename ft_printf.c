#include "ft_printf.h"




t_printf 	char_conv(t_printf p)
{
	printf ("CHAR CONV\n");
	return(p);
}

t_printf 	string_conv(t_printf p)
{
	printf ("STRING CONV\n");
	return(p);
}

t_printf 	locat_conv(t_printf p)
{
	printf ("ADRESSE CONV\n");
	return(p);
}

t_printf 	octo_conv(t_printf p)
{
	printf ("OCTO CONV\n");
	return(p);
}

t_printf 	dec_conv(t_printf p)
{
	printf ("DEC CONV\n");
	return(p);
}

t_printf 	exa_conv(t_printf p)
{
	printf ("EXA CONV\n");
	return(p);
}

t_printf 	mexa_conv(t_printf p)
{
	printf ("MEXA CONV\n");
	return(p);
}

t_printf 	float_conv(t_printf p)
{
	printf ("FLOAT CONV\n");
	return(p);
}

t_printf 	put_percent(t_printf p)
{
	printf ("PUT PERCENT\n");
	return(p);
}

int	ft_nbrlen(const int nbr)
{
	int	n;
	int	l;

	l = 0;
	n = nbr;
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	l++;
	return (l);
}

int	ft_ctoi(char c)
{
	int	i;

	i = c - '0';
	printf ("char : %c | i = %d\n", c, i);
	return(i);
}

int	ft_nbr_conv(t_printf p, int start, int val)
{
	int i;
	int nbr;
	int puissance;

	i = 0;
	nbr = 0;
	puissance = 1;
	while (i < val)
	{
		nbr += puissance * (ft_ctoi(p.conv[start - i]));
		puissance *= 10;
		i++;
	}
	return (nbr);
}

t_printf	put_nbr_modified(t_printf p)
{
	int	l;
	int	precision;
	int	i;

	i = 0;
	if (p.is_precision)
	{
		l = ft_nbrlen(p.d);
		precision = ft_nbr_conv(p, p.is_flag + p.is_width + p.is_precision, p.is_precision);
		printf("precision = %d | len = %d\n", precision, l);
		while (i++ < precision - l)
			ft_putchar('0');
	}
	if (p.plus && p.d >= 0)
		ft_putchar('+');
	ft_putnbr(p.d);
	return (p);	
}

t_printf	put_width(t_printf p)
{
	int width;
	
	width = ft_nbr_conv(p, p.is_flag + p.is_width - 1, p.is_width);
	printf ("width = %d\n", width);	
	return (p);
}

t_printf	flag_modifier(t_printf p)
{
	int	i;
	int	space;
	
	p.plus = 0;
	space = 0;
	i = 0;
	while (i < p.is_flag)
	{
		if (p.conv[i] == '-')
			p.minus++;
		if (p.conv[i] == '+')
			p.plus++;
		if (p.conv[i] == ' ')
			space++;
		i++;
	}
	if (space && !p.plus)
		ft_putchar(' ');
	return (p);
}

t_printf	is_modifier(t_printf p)
{
	char	c;
	int	point;
	int	number;

	point = 0;
	number = 0;
	p.c = 0;
	p.is_flag = 0;
	p.zero = 0;
	p.is_width = 0;
	p.is_precision = 0;
	while (p.c < p.diff)
	{
		c = p.conv[p.c];
		if (c == '-' || c == '+' || c == ' ' || c == '#')
			p.is_flag++;
		if (c == '0' && !number)
		{
			p.is_flag++;
			p.zero++;
		}
		if (c >= '1' && c <= '9' || (c == '0' && number))
		{
			number = 1;
			if (!point)
				p.is_width++;
			else
				p.is_precision++;
		}
		if (c == '.')
			point = 1;
		p.c++;
	}
	return (p);
}

t_printf	int_conv(t_printf p)
{
	int d;

	printf ("INT CONV\n");
	p.d = va_arg(p.arg, int);
	if (p.diff != 0)
	{
		//printf ("C//ARG SUPP Diff : %d\n", p.diff);
		p = is_modifier(p);
		p = flag_modifier(p);
		if (p.minus)
		{
			p = put_nbr_modified(p);
			p = put_width(p);
		}
		else
		{
			p = put_width(p);
			p = put_nbr_modified(p);
		}

		printf ("is_flags = %d | is_width = %d | is_precision = %d\n", p.is_flag, p.is_width, p.is_precision);
		p.c = 0;
		while (p.c < p.diff)
		{
			//printf ("C// char conv : %c | %d\n", p.conv[p.c], p.c);
			p.c++;
		}

	}
	return(p);
}
/*
t_printf	percent_found(t_printf p)
{
	//ft_putchar('>');
	ft_printf_int(p);
	//ft_putchar(p.format[p.i]);
	//ft_putstr("->");
	p.i += 2;
	return (p);
}
*/
int		check_error(t_printf p)
{
	p.i = 0;
	return (p.i);
}

t_printf	call_conv(t_printf p, t_printf ptmp)
{
	int i;

	i = 0;
	ptmp.diff = (p.i - 1) - ptmp.i;
	printf ("%d\n", ptmp.diff);
	while (i < ptmp.diff)
	{
		printf ("char : %c\n", p.conv[i]);
		ptmp.conv[i] = p.conv[i];
		i++;
	}
	if (p.format[p.i] == 'c')
		p = char_conv(ptmp);
	else if (p.format[p.i] == 's')
		p = string_conv(ptmp);
	else if (p.format[p.i] == 'p')
		p = locat_conv(ptmp);
	else if (p.format[p.i] == 'd' || p.format[p.i] == 'i')
		p = int_conv(ptmp);
	else if (p.format[p.i] == 'o')
		p = octo_conv(ptmp);
	else if (p.format[p.i] == 'u')
		p = dec_conv(ptmp);
	else if (p.format[p.i] == 'x')
		p = exa_conv(ptmp);
	else if (p.format[p.i] == 'X')
		p = mexa_conv(ptmp);
	else if (p.format[p.i] == 'f')
		p = float_conv(ptmp);
	else if (p.format[p.i] == '%')
		p = put_percent(ptmp);
	p.i += ptmp.diff + 1;
	return(p);
}

t_printf	check_conv(t_printf ptmp)
{
	t_printf p;

	p = ptmp;
	p.i++;
	//printf ("C//current i : %d\n", p.i);
	while(p.format[p.i] != 'c' &&\
			p.format[p.i] != 's' &&\
			p.format[p.i] != 'p' &&\
			p.format[p.i] != 'd' &&\
			p.format[p.i] != 'i' &&\
			p.format[p.i] != 'o' &&\
			p.format[p.i] != 'u' &&\
			p.format[p.i] != 'x' &&\
			p.format[p.i] != 'X' &&\
			p.format[p.i] != 'f' &&\
			p.format[p.i] != '%')
	{
		//printf ("C//Current char : %c | pos : %d\n", p.format[p.i], p.i);
		p.conv[p.c] = p.format[p.i];
		printf ("assigned : %c | char assign : %c\n", p.conv[p.c], p.format[p.i]);
		p.c++;
		p.i++;
	}
	//printf ("C//Current conv : %%%c\n", p.format[p.i]);
	p = call_conv(p, ptmp);
	p.i++;
	//printf ("C// Check return char : %c | i : %d\n", p.format[p.i], p.i);
	return(p);
}

t_printf	ft_printf(const char *format, ...)
{
	t_printf p;
	p.i = 0;
	p.c = 0;
	p.format = ft_strdup(format);
	//printf ("C//Len : %d\n", ft_strlen(p.format));
	check_error(p);
	//check_conv(p);
	va_start(p.arg, format);
	while (p.format[p.i])
	{
		if (p.format[p.i] == '%')
		{
			p = check_conv(p);
			//printf ("C// Check return char : %c | i : %d\n", p.format[p.i], p.i);
			//p = percent_found(p);
		}
		else
		{
			write(1, &p.format[p.i], 1);
			p.i++;
		}
	}
	va_end(p.arg);
	ft_putchar('\n');
	return (p);
}

int		main(int argc, char **argv)
{
	argc++;
	t_printf p;
	//printf("C// %% ca fait quoi ?\n");
	p = ft_printf(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	//printf ("C//p.i = %d", p.i);
	return (0);
}
