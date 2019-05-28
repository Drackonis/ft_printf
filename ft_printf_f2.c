/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:17:15 by dieroyer          #+#    #+#             */
/*   Updated: 2019/05/28 18:23:17 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	float_conv(t_printf p)
{
	p = is_modifier(p);
	if (p.f_precision == 0)
		p.f_precision = 6;
	if (p.lcount > 0)
	{
		p.m = va_arg(p.arg, double);
		p.isneg = (p.m < 0) ? 1 : 0;
		ft_printf_lf(p.m, p.strf, p.f_precision);
	}
	else if (p.Lcount > 0)
	{
		p.l = va_arg(p.arg, long double);
		p.isneg = (p.l < 0) ? 1 : 0;
		ft_printf_blf(p.l, p.strf, p.f_precision);
	}
	else
	{
		p.n = va_arg(p.arg, double);
		p.isneg = (p.n < 0) ? 1 : 0;
		ft_printf_f(p.n, p.strf, p.f_precision);
	}
	p.numlen = ft_strlen(p.strf);
	ft_getconv(p, -1, p.numlen);
	return (p);
}
