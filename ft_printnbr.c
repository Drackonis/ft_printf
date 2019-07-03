/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:22:34 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/03 17:07:32 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

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
		else if (p.baseconv == 3 && p.d5 != 0)
			ft_putstr("0x");
		else if (p.baseconv == 4 && p.d5 != 0)
			ft_putstr("0X");
	}
	if ((p.baseconv >= 3 && p.sharp && p.d5 != 0) || p.baseconv == 5)
		p.ret += 2;
	return (p);
}

void			printf_base_ll_nbr(t_printf p)
{
	if (p.baseconv == 1)
		ft_putunbr(p.d7);
	else if (p.baseconv == 2)
		ft_putunbr_ll_base(p.d3, "01234567");
	else if (p.baseconv == 3)
		ft_putunbr_ll_base(p.d3, "0123456789abcdef");
	else if (p.baseconv == 4)
		ft_putunbr_ll_base(p.d3, "0123456789ABCDEF");
}

t_printf		print_base_nbr(t_printf p)
{
	if (((p.baseconv == 1 && p.d7 == 0) ||\
		(p.baseconv != 5 && p.d5 == 0) || (p.baseconv == 2 && p.d5 == 0))\
			&& p.d3 == 0)
	{
		if (p.f_precision != 0 || !p.prec_point)
			write(1, "0", 1);
		else if (p.f_width > 0)
			write(1, " ", 1);
		else
			p.ret--;
	}
	else if (p.lcount == 2)
		printf_base_ll_nbr(p);
	else if (p.baseconv == 1)
		ft_putunbr(p.d7);
	else if (p.baseconv == 2)
		ft_putunbr_base(p.d5, "01234567");
	else if (p.baseconv == 3)
		ft_putunbr_base(p.d5, "0123456789abcdef");
	else if (p.baseconv == 4)
		ft_putunbr_base(p.d5, "0123456789ABCDEF");
	else if (p.baseconv == 5)
		ft_putunbr_base(p.d6, "0123456789abcdef");
	return (p);
}

t_printf		print_nbr(t_printf p)
{
	if (p.baseconv == 0 && !(p.d4 == 0 && p.prec_point && p.f_precision == 0))
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
		{
			if (p.errorf)
				ft_putchar('0');
			ft_putstr(p.strf);
		}
		else if (p.baseconv == -2)
			ft_putchar('%');
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
