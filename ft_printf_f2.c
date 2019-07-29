/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:17:15 by dieroyer          #+#    #+#             */
/*   Updated: 2019/07/29 15:34:38 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	float_conv(t_printf p)
{
	if (p.prec_point == 0)
		p.f_precision = 6;
	if (p.blcount > 0)
	{
		p.l = va_arg(p.arg, long double);
		p.isneg = (p.l < 0) ? 1 : 0;
		ft_printf_blf(p.l, p.strf, p.f_precision, p);
	}
	else
	{
		p.m = va_arg(p.arg, double);
		p.isneg = (p.m < 0) ? 1 : 0;
		ft_printf_lf(p.m, p.strf, p.f_precision, p);
	}
	p.numlen = ft_strlen(p.strf);
	p.ret += ft_strlen(p.strf);
	return (p);
}

t_printf	error_f(t_printf p)
{
	p.errorf = 0;
	if (p.strf[0] == '.')
	{
		p.errorf = 1;
	}
	return (p);
}
