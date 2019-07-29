/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:22:34 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/29 15:56:44 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		put_mp(t_printf p)
{
	if (p.plus && !p.isneg && !p.pput)
	{
		p.ret++;
		p.pput++;
		ft_putchar('+');
	}
	if (p.isneg && !p.mput && p.baseconv < 1)
	{
		ft_putchar('-');
		p.mput++;
		p.ret++;
	}
	return (p);
}

t_printf		put_width3(t_printf p, int width)
{
	int			i;

	i = 0;
	p = put_mp(p);
	p = put_sharp(p);
	while (i < width)
	{
		(p.baseconv >= 1 && ((p.d4 == 0 && p.f_precision > 0)\
		|| p.prec_point)) ? ft_putchar(' ') : ft_putchar('0');
		i++;
		p.ret++;
	}
	return (p);
}

t_printf		put_width2(t_printf p, int width)
{
	int			i;

	i = 0;
	if (p.zero && !p.minus && p.is_precision == 0)
		p = put_width3(p, width);
	else
	{
		while (i < width)
		{
			((p.baseconv == -2 || p.baseconv == -1) && p.zero)\
				? ft_putchar('0') : ft_putchar(' ');
			i++;
			p.ret++;
		}
		if (p.baseconv == -1)
			p = put_mp(p);
	}
	return (p);
}

t_printf		put_width(t_printf p)
{
	int			width;
	int			precision;

	width = p.f_width;
	if ((p.space && p.baseconv <= 0) || (p.plus && !p.isneg) ||\
			(p.isneg && p.baseconv <= 0))
		width--;
	if (p.is_precision)
	{
		precision = p.f_precision;
		precision -= p.numlen;
		precision -= (p.baseconv == 2 && p.sharp && p.d4 != 0) ? 1 : 0;
		precision = (precision < 0) ? 0 : precision;
		width -= precision;
	}
	width -= (p.baseconv == 2 && p.d4 == 0 && p.sharp) ? 0 : p.numlen;
	p = put_width2(p, width);
	if (!p.zero && !p.minus && p.is_precision == 0)
		p = put_sharp(p);
	return (p);
}

t_printf		put_start_space(t_printf p)
{
	if (p.space && !p.plus && p.d >= 0 && p.baseconv == 0 && !p.isneg)
	{
		ft_putchar(' ');
		p.ret++;
	}
	return (p);
}
