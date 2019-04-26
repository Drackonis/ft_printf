#include "ft_printf.h"
#include "libft/libft.h"
#include <wchar.h>

//void		char_conv(t_printf p, int *ret)
t_printf	char_conv(t_printf p)
{
	//Tester avec : ./a.exe " Test char %-+0c et int %0 +-5.7d" "x" "42"
	//Modifier le main (pas de atoi mais envoyez un char à la place)
	//Variable utiles :
	//p.format (char*) contient la chaine de charactere entiere passé par l'utilisateur 
	//p.conv (char*) contient les éventuels flags se trouvant entre le '%' et le 'c'
	//p.i (int) c'est la position du % dans p.format
	//p.diff (int) c'est la position du dernier flags dans p.conv, si p.diff est égal à 0 il n'y à pas de flags
	//printf ("Chaine de charactere : %s | chaine de flags : %s\n", p.format, p.conv);
	//printf ("Position du %% dans la chaine de charactere : %c | position du dernier charactere avant le c %c | p.diff : %d\n", p.format[p.i], p.conv[p.diff - 1], p.diff);
//	printf("ici %s\n", p.conv);
	p = is_modifier(p);
	printf("%c\n", p.format[p.i]);
//	printf("lcount %d\n", p.lcount);
	char c;
	void *v;

	if (p.format[p.i + 1] == 'C' || (p.format[p.i + 2] == 'c' && p.lcount == 1))
	{
		v = va_arg(p.arg, void*);
		p.ret++;
		ft_putchar((char)c);
	}
	else
	{
		c = (char)va_arg(p.arg, int);
		p.ret++;
		ft_putchar(c);
	}
	return(p);
}

t_printf 	string_conv(t_printf p)
{
	char *str;
	void *v;
	int		i;
	
	i = 0;
	if (p.format[p.i + 1] == 'S' || (p.format[p.i + 2] == 's' && p.lcount == 1))
	{
		v = va_arg(p.arg, wchar_t *);
		if (v != NULL)
		{
			ft_putstr(v);
			p.ret += ft_strlen(v);
		}
	}	
	if (p.format[p.i + 1] == 's')
	{
		str = va_arg(p.arg, char*);
		ft_putstr(str);
		p.ret += ft_strlen(str);
	}
	else
	{
		ft_putstr("(null)");
		p.ret += 6;
	}
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

void	ft_putnbr_intmax(intmax_t num)
{
	intmax_t		nb;
	int			t;
	char			c;

	t = 0;
	nb = num;
	if (nb >= 10)
	{
		t = nb % 10;
		c = t + 48;
		ft_putnbr_intmax(nb / 10);
	}
	else
		c = nb + 48;
	write(1, &c, 1);
}

int	ft_nbrlen(intmax_t n)
{
	int		l;

	//ATTENTION PUTWIDTH DOIT GET LA LONGUEUR SANS LE -
	l = 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	l++;
	//printf ("\n len = %d\n", l);
	return (l);
}

int	ft_ctoi(char c)
{
	int	i;

	i = c - '0';
	//printf ("char : %c | i = %d\n", c, i);
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
		//printf ("CHAR CONV : %c | s-i : %d\n", p.conv[start - i], start - i);
		nbr += puissance * (ft_ctoi(p.conv[start - i]));
		puissance *= 10;
		i++;
	}
	//printf ("\nNRE RETURN : %d\n", nbr);
	return (nbr);
}

t_printf	put_nbr_modified(t_printf p)
{
	int	l;
	int	precision;
	int	i;

	i = 0;
	if (p.plus && !p.isneg)
	{
		p.ret++;
		ft_putchar('+');
	}
	if (p.isneg && !p.mput)
	{
		ft_putchar('-');
		p.mput++;
		p.ret++;
	}
	if (p.is_precision)
	{
		l = p.numlen;
		//printf ("NUMLEN = %d", l);
		precision = ft_nbr_conv(p, p.is_flag + p.is_width + p.is_precision, p.is_precision);
		//printf ("PRECISION : |%d|\n", precision);
		//printf("precision = %d | len = %d\n", precision, l);
		while (i++ < precision - l)
		{
			ft_putchar('0');
			p.ret++;
		}
	}
	if (!p.isneg)
		ft_putnbr_intmax(p.d4);
	else
		ft_putnbr(-p.d4);
	return (p);	
}

t_printf	put_width(t_printf p)
{
	int	width;
	int	precision;
	int	i;

	i = 0;
	width = ft_nbr_conv(p, p.is_flag + p.is_width - 1, p.is_width);
	//printf ("WIDTH : |%d|\n", width);
	if (p.space || (p.plus && !p.isneg) || p.isneg)
	{
		width--;
		//printf ("Width-- : %d\n", width);
	}
	if (p.is_precision)
	{
		precision = ft_nbr_conv(p, p.is_flag + p.is_width + p.is_precision, p.is_precision);
		//printf ("\nPrecision : %d\n", precision);
		
		precision -= ft_nbrlen(p.d);
		if (precision < 0)
			precision = 0;
		width -= precision;
		//printf ("WIDTH : |%d|\n", width);
	}
	//printf ("Remove nbrlen : %d | width : %d\n", ft_nbrlen(p.d), width);
	width = width - ft_nbrlen(p.d);
	//printf ("width : %d\n", width);
	//printf ("printed width : %d | nbrlen : %d | p.d : %d\n", width, ft_nbrlen(p.d), p.d);
	if (p.zero && !p.minus && p.is_precision == 0)
	{
		if (p.isneg && !p.mput)
		{
			ft_putchar('-');
			p.mput++;
			p.ret++;
		}
		while (i < width)
		{
			ft_putchar('0');
			i++;
			p.ret++;
		}
	}
	else
	{
		while (i < width)
		{
			ft_putchar (' ');
			i++;
			p.ret++;
		}
		/*if (p.d < 0)
			ft_putchar('-');*/
	}
	//printf ("\nwidth = %d\n", width);	
	return (p);
}

t_printf	flag_modifier(t_printf p)
{
	int	i;

	p.minus = 0;
	p.mput = 0;
	p.plus = 0;
	p.space = 0;
	i = 0;
	while (i < p.is_flag)
	{
		if (p.conv[i] == '-')
			p.minus++;
		if (p.conv[i] == '+')
			p.plus++;
		if (p.conv[i] == ' ')
			p.space++;
		i++;
	}
	if (p.space && !p.plus && p.d >= 0)
	{
		ft_putchar(' ');
		p.ret++;
	}
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
	p.hcount = 0;
	p.lcount = 0;
	while (p.c < p.diff)
	{
		c = p.conv[p.c];
		if (c == '-' || c == '+' || c == ' ')
			p.is_flag++;
		else if (c == '0' && !number)
		{
			p.is_flag++;
			p.zero++;
		}
		else if (c == '.' /*&& point == 0*/)
			point += 1;
		else if ((c >= '1' && c <= '9') || (c == '0' && number))
		{
			number = 1;
			if (point == 0)
				p.is_width++;
			else
				p.is_precision++;
		}
		else if (c == 'h')
			p.hcount++;
		else if (c == 'l')
			p.lcount++;
		/*else
			ft_putstr("Format error : %[flags][width][.precision][size]type");*/
		p.c++;
	}
	return (p);
}

int	 		int_init_error(t_printf p)
{
	char		c;
	int		i;
	int		nbPoint;

	nbPoint = 0;
	i = p.c;
	c = p.conv[i];
	while (i < p.diff && (c == '-' || c == '+' || c == ' '))
	{
		i++;
		c = p.conv[i];
	}
	while (i < p.diff && ((c >= '0' && c <= '9') || c == '.'))
	{
		if (c == '.')
			nbPoint++;
		/*if (nbPoint > 1)
			ft_putstr("Format error : %[flags][width][.precision][size]type");*/
		i++;
		c = p.conv[i];
	}
	while (i < p.diff && (c == 'h' || c == 'l'))
	{
		i++;
		c = p.conv[i];
	}
	/*if (i != p.diff)
		ft_putstr("Format error : %[flags][width][.precision][size]type");*/
	return (0);
}

t_printf	get_arg(t_printf p)
{
	p.d = 0;
	p.d0 = 0;
	p.d1 = 0;
	p.d2 = 0;
	p.d3 = 0;
	p.d4 = 0;
	p.isneg = 0;
	if (p.hcount > 0)
	{
		//short & signed char is promoted to int when pass in va_arg
		if (p.hcount == 1)
		{
			p.d1 = (short)va_arg(p.arg, int);
			p.isneg = (p.d1 < 0) ? 1 : 0;
			p.numlen = ft_nbrlen(p.d1);
			p.d4 = (intmax_t)p.d1;
		}
		else if (p.hcount == 2)
		{
			p.d0 = (signed char)va_arg(p.arg, int);
			p.isneg = (p.d0 < 0) ? 1 : 0;
			p.numlen = ft_nbrlen(p.d0);
			p.d4 = (intmax_t)p.d0;
		}
	}
	else if (p.lcount > 0)
	{
		if (p.lcount == 1)
		{
			p.d2 = va_arg(p.arg, long);
			p.isneg = (p.d2 < 0) ? 1 : 0;
			p.numlen = ft_nbrlen(p.d2);
			p.d4 = (intmax_t)p.d2;
		}
		else if (p.lcount == 2)
		{
			p.d3 = va_arg(p.arg, long long);
			p.isneg = (p.d3 < 0) ? 1 : 0;
			p.numlen = ft_nbrlen(p.d3);
			p.d4 = (intmax_t)p.d3;
		}
	}
	else
	{
		p.d = va_arg(p.arg, int);
		p.isneg = (p.d < 0) ? 1 : 0;
		p.numlen = ft_nbrlen(p.d);
		p.d4 = (intmax_t)p.d;
	}
	p.ret += p.numlen;
	return (p);
}

t_printf	int_conv(t_printf p)
{
	//printf ("INT CONV\n");
	//printf ("C//ARG SUPP Diff : %d\n", p.diff);
	int_init_error(p);
	p = is_modifier(p);
	p = flag_modifier(p);
	p = get_arg(p);
	//printf ("MINUS : %d\n", p.minus);
	if (p.minus)
	{
		//printf ("put nbr modified in first : MINUS > 0\n");
		p = put_nbr_modified(p);
		p = put_width(p);
	}
	else
	{
		//printf ("put whidth in first : MINUS <= 0 \n");
		p = put_width(p);
		p = put_nbr_modified(p);
	}
	//printf ("\nis_flags = %d | is_width = %d | is_precision = %d | hcount = %d | lcount %d\n", p.is_flag, p.is_width, p.is_precision, p.hcount, p.lcount);
	p.c = 0;
	while (p.c < p.diff)
	{
		//printf ("C// char conv : %c | %d\n", p.conv[p.c], p.c);
		p.c++;
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
	//printf ("Diff :%d\n", ptmp.diff);
	while (i < ptmp.diff)
	{
		//printf ("Copied char : %c | p.i : %d\n", p.conv[i], i);
		ptmp.conv[i] = p.conv[i];
		i++;
	}
	//printf ("Current char conv : %c\n", p.format[p.i]);
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
	return (p);
}

t_printf	check_conv(t_printf ptmp)
{
	t_printf p;

	p = ptmp;
	p.i++;
	//printf ("C//current i : %d\n", p.i);
	p.c = 0;
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
		//printf ("assigned : %c | char assign : %c | p.c : %d\n", p.conv[p.c], p.format[p.i], p.c);
		p.c++;
		p.i++;
	}
	//printf ("C//Current conv : %%%c\n", p.format[p.i]);
	p = call_conv(p, ptmp);
	p.i++;
	//printf ("C// Check return char : %c | i : %d\n", p.format[p.i], p.i);
	return(p);
}

int		ft_printf(const char *format, ...)
{
	t_printf p;
	p.i = 0;
	p.c = 0;
	p.ret = 0;
	//int ret = 0; c ici qu'il faut l'initier;
	p.format = ft_strdup(format);
	//printf ("C//Len : %d\n", ft_strlen(p.format));
	check_error(p);
	//check_conv(p);
	va_start(p.arg, format);
	while (p.format[p.i])
	{
		if (p.format[p.i] == '%')
		{
			//printf ("\n_____%% FOUND_____\n");
			p = check_conv(p);
			//printf ("C// Check return char : %c | i : %d\n", p.format[p.i], p.i);
			//p = percent_found(p);
		}
		else
		{
			write(1, &p.format[p.i], 1);
			p.ret++;
			p.i++;
		}
	}
	va_end(p.arg);
	ft_putchar('\n'); /*//ATTENTION !!!!!!\\*/
	return (p.ret);
	//return (ret);
}

int		main(int argc, char **argv)
{
	int	ret;
	argc++;
	t_printf p;
//	char *i = "qwertyuio";
	void *c = "o";
	printf("TRUE PRINTF : \n");
	printf(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	printf("\nMY PRINTF   : \n");
	//printf("C// %% ca fait quoi ?\n");
	ret = ft_printf(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	ft_putchar('\n');
	//ft_printf("salut mdrrrrrrrr %C\n", c);
	printf ("RET = %d\n", ret);
	//printf ("C//p.i = %d", p.i);
	printf ("\n");
	return (0);
}
