/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:17:15 by dieroyer          #+#    #+#             */
/*   Updated: 2019/05/21 18:23:48 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf 	float_conv(t_printf p)
{
	double 		m;
	long double l;
	float 		n;

	p = is_modifier(p);
	if (p.f_precision == 0)
		p.f_precision = 6;
	if (p.lcount > 0)
	{
		m = va_arg(p.arg, double);
		p.isneg = (m < 0) ? 1 : 0;
		ft_printf_lf(m, p.strf, p.f_precision);
	}
	else if (p.Lcount > 0)
	{
		l = va_arg(p.arg, long double);
		p.isneg = (l < 0) ? 1 : 0;
		ft_printf_blf(l, p.strf, p.f_precision);
	}
	else
	{
		n = va_arg(p.arg, double);
		p.isneg = (n < 0) ? 1 : 0;
		ft_printf_f(n, p.strf, p.f_precision);
	}
	p.numlen = ft_strlen(p.strf);
	ft_getconv(p, -1, p.numlen);
	return (p);
}
