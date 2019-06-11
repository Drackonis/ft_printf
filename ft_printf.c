/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:59:58 by rkergast          #+#    #+#             */
/*   Updated: 2019/06/11 17:32:38 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <wchar.h>
#include <string.h>

void			ft_putnbr_intmax(intmax_t num)
{
	intmax_t	nb;
	int			t;
	char		c;

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

int				ft_nbrlen(intmax_t n)
{
	int			l;

	l = 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	l++;
	return (l);
}

int				ft_ctoi(char c)
{
	int			i;

	i = c - '0';
	return (i);
}

int				ft_nbr_conv(t_printf p, int start, int val)
{
	int			i;
	int			nbr;
	int			puissance;

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

t_printf		put_sharp(t_printf p)
{
	if (p.baseconv == 5)
	{
		ft_putstr("0x");
	}
	if (p.sharp)
	{
		if (p.baseconv == 2)
		{
			ft_putstr("0");
			p.ret++;
		}
		else if (p.baseconv == 3)
			ft_putstr("0x");
		else if (p.baseconv == 4)
			ft_putstr("0X");
	}
	if ((p.baseconv >= 3 && p.sharp) || p.baseconv == 5)
		p.ret += 2;
	return (p);
}

t_printf		print_base_nbr(t_printf p)
{
	if (p.baseconv == 1)
		ft_putnbr_base(p.d5, "0123456789");
	else if (p.baseconv == 2)
		ft_putnbr_base(p.d5, "01234567");
	else if (p.baseconv == 3)
		ft_putnbr_base(p.d5, "0123456789abcdef");
	else if (p.baseconv == 4)
		ft_putnbr_base(p.d5, "0123456789ABCDEF");
	else if (p.baseconv == 5)
		ft_putnbr_base(p.d6, "0123456789abcdef");
	if (p.d5 == 0)
	{
		write(1, "0", 1);
		p.ret++;
	}
	return (p);
}

t_printf		print_nbr(t_printf p)
{
	if (p.baseconv == 0)
	{
		if (!p.isneg)
			ft_putnbr_intmax(p.d4);
		else
			ft_putnbr_intmax(-p.d4);
	}
	else
	{
		if (p.baseconv >= 1)
			p = print_base_nbr(p);
		else if (p.baseconv == -1)
			ft_putstr(p.strf);
		else if (p.baseconv == -2)
			ft_putchar('%');
	}
	return (p);
}

t_printf		put_mp(t_printf p)
{
	if (p.plus && !p.isneg && !p.pput)
	{
		p.ret++;
		p.pput++;
		ft_putchar('+');
	}
	if (p.isneg && !p.mput)
	{
		ft_putchar('-');
		p.mput++;
		p.ret++;
	}
	return (p);
}

t_printf		put_nbr_modified(t_printf p)
{
	int			i;
	int			precision;

	i = 0;
	precision = p.f_precision;
	p = put_mp(p);
	if (p.is_precision)
	{
		p = put_sharp(p);
		while (i++ < precision - p.numlen)
		{
			ft_putchar('0');
			p.ret++;
		}
	}
	else if (p.minus)
		p = put_sharp(p);
	p = print_nbr(p);
	return (p);
}

t_printf		put_width2(t_printf p, int width)
{
	int			i;

	i = 0;
	if (p.zero && !p.minus && p.is_precision == 0)
	{
		p = put_mp(p);
		p = put_sharp(p);
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
			(p.baseconv == -2 && p.zero) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			p.ret++;
		}
	}
	return (p);
}

t_printf		put_width(t_printf p)
{
	int			width;
	int			precision;

	width = p.f_width;
	if ((p.space && p.baseconv <= 0) || (p.plus && !p.isneg) || p.isneg)
		width--;
	if (p.is_precision)
	{
		precision = p.f_precision;
		precision -= p.numlen;
		if (precision < 0)
			precision = 0;
		width -= precision;
	}
	width -= p.numlen;
	p = put_width2(p, width);
	if (!p.zero && !p.minus && p.is_precision == 0)
		p = put_sharp(p);
	return (p);
}

t_printf		get_wipr(t_printf p)
{
	p.f_width = ft_nbr_conv(p, p.is_flag + p.is_width - 1, p.is_width);
	if (p.is_precision)
		p.f_precision = ft_nbr_conv(p, p.is_flag + p.is_width +\
				p.is_precision, p.is_precision);
	return (p);
}

t_printf		get_hll(t_printf p, char c)
{
	if (c == 'h')
		p.hcount++;
	else if (c == 'l')
		p.lcount++;
	else if (c == 'L')
		p.Lcount++;
	return (p);
}

t_printf		get_is_wipr(t_printf p, int point)
{
	if (point == 0)
		p.is_width++;
	else
		p.is_precision++;
	return (p);
}

t_printf		flag_modifier(t_printf p)
{
	int		i;

	i = 0;
	while (i < p.is_flag)
	{
		if (p.conv[i] == '-')
			p.minus++;
		else if (p.conv[i] == '+' && p.baseconv == 0)
			p.plus++;
		else if (p.conv[i] == ' ')
			p.space++;
		else if (p.conv[i] == '#')
			p.sharp++;
		i++;
	}
	return (p);
}

int				int_init_error(t_printf p)
{
	char		c;
	int			i;
	int			nbpoint;

	nbpoint = 0;
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
			nbpoint++;
		i++;
		c = p.conv[i];
	}
	while (i < p.diff && (c == 'h' || c == 'l'))
	{
		i++;
		c = p.conv[i];
	}
	return (0);
}

t_printf		get_arg_h(t_printf p)
{
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
	return (p);
}

t_printf		get_arg_l(t_printf p)
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
	return (p);
}

t_printf		get_arg_base(t_printf p, int current_base)
{
	if (p.baseconv < 5)
	{
		p.d5 = va_arg(p.arg, unsigned int);
		p.numlen = ft_nbrlen_base(p.d5, current_base);
		p.d4 = (intmax_t)p.d5;
	}
	else
	{
		p.d6 = (uintptr_t)va_arg(p.arg, void*);
		p.numlen = ft_nbrlen_base(p.d6, current_base);
		p.d4 = (intmax_t)p.d6;
	}
	return (p);
}

t_printf		get_int_arg(t_printf p)
{
	p.d = va_arg(p.arg, int);
	p.isneg = (p.d < 0) ? 1 : 0;
	p.numlen = ft_nbrlen(p.d);
	p.d4 = (intmax_t)p.d;
	return (p);
}

t_printf		get_arg(t_printf p)
{
	int			current_base;

	current_base = 10;
	if (p.baseconv == -2)
	{
		p.numlen = 1;
		p.f_precision = 0;
	}
	else if (p.baseconv > 0 && p.hcount == 0 && p.lcount == 0)
	{
		if (p.baseconv == 2)
			current_base = 8;
		else if (p.baseconv > 2)
			current_base = 16;
		p = get_arg_base(p, current_base);
	}
	else if (p.hcount > 0)
		p = get_arg_h(p);
	else if (p.lcount > 0)
		p = get_arg_l(p);
	else
		p = get_int_arg(p);
	p.ret += p.numlen;
	return (p);
}

t_printf		range_sharp(t_printf p)
{
	if (p.baseconv == 5 || (p.baseconv >= 3 && p.sharp))
		p.f_width -= 2;
	if (p.baseconv == 2 && p.sharp)
		p.f_width--;
	return (p);
}

t_printf		put_start_space(t_printf p)
{
	if (p.space && !p.plus && p.d >= 0 && p.baseconv == 0 && !p.isneg)
	{
		ft_putchar(' ');
		p.ret++;
	}
	return(p);
}

t_printf		get_start_flags(t_printf p, char c, int number)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#')
		p.is_flag++;
	else if (c == '0' && !number)
	{
		p.is_flag++;
		p.zero++;
	}
	return (p);
}

t_printf		is_modifier(t_printf p)
{
	char	c;
	int		point;
	int		number;

	point = 0;
	number = 0;
	while (p.c < p.diff)
	{
		c = p.conv[p.c];
		p = get_start_flags(p, c, number);
		if (c == '.')
			point += 1;
		else if (((c >= '1' && c <= '9') || (c == '0' && number)))
		{
			number = 1;
			p = get_is_wipr(p, point);
		}
		else
			p = get_hll(p, c);
		p.c++;
	}
	p = get_wipr(p);
	return (p);
}

t_printf		intialize2(t_printf p)
{
	p.d = 0;
	p.d0 = 0;
	p.d1 = 0;
	p.d2 = 0;
	p.d3 = 0;
	p.d4 = 0;
	p.d5 = 0;
	p.d6 = 0;
	return (p);
}

t_printf		initialize(t_printf p)
{
	p.c = 0;
	p.is_flag = 0;
	p.zero = 0;
	p.is_width = 0;
	p.is_precision = 0;
	p.hcount = 0;
	p.lcount = 0;
	p.f_precision = 0;
	p.f_width = 0;
	p.Lcount = 0;
	p.minus = 0;
	p.mput = 0;
	p.pput = 0;
	p.plus = 0;
	p.space = 0;
	p.sharp = 0;
	p.isneg = 0;
	p.numlen = 0;
	p = intialize2(p);
	return (p);
}

t_printf		get_conv(t_printf p)
{
	p = initialize(p);
	p = is_modifier(p);
	p = flag_modifier(p);
	p = range_sharp(p);
	p = get_arg(p);
	p = put_start_space(p);
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
	p.c = 0;
	while (p.c < p.diff)
		p.c++;
	return (p);
}

t_printf		locat_conv(t_printf p)
{
	p.baseconv = 5;
	p = get_conv(p);
	return (p);
}

t_printf		put_percent(t_printf p)
{
	p.baseconv = -2;
	p = get_conv(p);
	return (p);
}

t_printf		octo_conv(t_printf p)
{
	p.baseconv = 2;
	p = get_conv(p);
	return (p);
}

t_printf		dec_conv(t_printf p)
{
	p.baseconv = 1;
	p = get_conv(p);
	return (p);
}

t_printf		exa_conv(t_printf p)
{
	p.baseconv = 3;
	p = get_conv(p);
	return (p);
}

t_printf		mexa_conv(t_printf p)
{
	p.baseconv = 4;
	p = get_conv(p);
	return (p);
}

t_printf		int_conv(t_printf p)
{
	p = get_conv(p);
	return (p);
}

int				check_error(t_printf p)
{
	p.i = 0;
	return (p.i);
}

t_printf		init_call_conv(t_printf ptmp, t_printf p)
{
	int			i;

	i = 0;
	ptmp.diff = (p.i - 1) - ptmp.i;
	while (i < ptmp.diff)
	{
		ptmp.conv[i] = p.conv[i];
		i++;
	}
	return (ptmp);
}

t_printf		do_conv(t_printf p, t_printf ptmp)
{
	if (p.format[p.i] == 'c' || p.format[p.i] == 'C')
		p = char_conv(ptmp);
	else if (p.format[p.i] == 's')
		p = string_conv(ptmp);
	else if (p.format[p.i] == 'S'
			|| (p.format[p.i] == 's' && p.format[p.i - 1] == 'l'))
		p = str_bonus(ptmp);
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
		p = ft_getconv(ptmp, -1, 0);
	else if (p.format[p.i] == '%')
		p = put_percent(ptmp);
	return (p);
}

t_printf		call_conv(t_printf p, t_printf ptmp)
{
	ptmp = init_call_conv(ptmp, p);
	p = do_conv(p, ptmp);
	p.i += ptmp.diff + 1;
	return (p);
}

t_printf		check_conv(t_printf ptmp)
{
	t_printf p;

	p = ptmp;
	p.i++;
	p.c = 0;
	while (p.format[p.i] != 'c' &&\
			p.format[p.i] != 's' &&\
			p.format[p.i] != 'p' &&\
			p.format[p.i] != 'd' &&\
			p.format[p.i] != 'i' &&\
			p.format[p.i] != 'o' &&\
			p.format[p.i] != 'u' &&\
			p.format[p.i] != 'x' &&\
			p.format[p.i] != 'X' &&\
			p.format[p.i] != 'f' &&\
			p.format[p.i] != 'S' &&\
			p.format[p.i] != '%')
	{
		p.conv[p.c] = p.format[p.i];
		p.c++;
		p.i++;
	}
	p = call_conv(p, ptmp);
	p.i++;
	return (p);
}

int				ft_printf(const char *format, ...)
{
	t_printf	p;

	p.i = 0;
	p.c = 0;
	p.ret = 0;
	p.baseconv = 0;
	p.format = ft_strdup(format);
	check_error(p);
	va_start(p.arg, format);
	while (p.format[p.i])
	{
		if (p.format[p.i] == '%')
		{
			p = check_conv(p);
		}
		else
		{
			write(1, &p.format[p.i], 1);
			p.ret++;
			p.i++;
		}
	}
	va_end(p.arg);
	return (p.ret);
}
/*
**int		main(int argc, char **argv)
**{
**	int ret = 0;
**	int true_ret = 0;
**	char y;
**	argc++;
**	printf("TRUE PRINTF :\n");
**	true_ret = printf(argv[1], ft_atoi(argv[2]));
**	printf ("\n");
**	write(1,"MY PRINTF :", 11);
**	printf ("\n");
**	ret = ft_printf(argv[1], ft_atoi(argv[2]));
**	printf("\nTRUE RET = %d\nMY RET = %d\n", true_ret, ret);
**	return (0);
**}
*/
