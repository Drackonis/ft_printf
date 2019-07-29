/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:22:34 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/29 15:06:47 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		get_base_arg(t_printf p)
{
	if (p.lcount > 0 && p.current_base != 10)
	{
		p.d8 = va_arg(p.arg, unsigned long long);
		p.numlen = ft_nbrulen_base(p.d8, p.current_base);
		p.d4 = (intmax_t)p.d8;
	}
	else
	{
		p.d3 = va_arg(p.arg, long long);
		p.numlen = ft_nbrlen(p.d3);
		p.d4 = (intmax_t)p.d3;
	}
	return (p);
}

t_printf		get_arg_h(t_printf p)
{
	if (p.hcount == 1)
	{
		p.d1 = (short)va_arg(p.arg, int);
		p.isneg = (p.d1 < 0) ? 1 : 0;
		p.numlen = ft_nbrhlen_base(p.d1, p.current_base);
		p.d4 = (intmax_t)p.d1;
	}
	else if (p.hcount == 2)
	{
		p.d0 = (signed char)va_arg(p.arg, int);
		p.isneg = (p.d0 < 0) ? 1 : 0;
		p.numlen = ft_nbrhlen_base(p.d0, p.current_base);
		p.d4 = (intmax_t)p.d0;
	}
	return (p);
}

t_printf		get_arg_l(t_printf p)
{
	if (p.baseconv != 0)
		p = get_base_arg(p);
	else if (p.lcount == 1)
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
	if (p.baseconv == 1)
	{
		p.d7 = va_arg(p.arg, unsigned long);
		p.numlen = ft_nbrulen_base(p.d7, current_base);
		p.d5 = (unsigned int)p.d7;
	}
	else if (p.baseconv < 5)
	{
		p.d5 = va_arg(p.arg, unsigned int);
		p.numlen = ft_nbrlen_base(p.d5, current_base);
		p.d4 = (intmax_t)p.d5;
	}
	else
	{
		p.d8 = (unsigned long long)va_arg(p.arg, void*);
		p.numlen = ft_nbrulen_base(p.d8, current_base);
		p.d4 = (intmax_t)p.d8;
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
