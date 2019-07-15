/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:22:34 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/15 18:07:01 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		get_is_wipr(t_printf p)
{
	if (p.prec_point == 0)
		p.is_width++;
	else
		p.is_precision++;
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
		p.blcount++;
	return (p);
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

t_printf		range_sharp(t_printf p)
{
	if (p.baseconv == 5 || (p.baseconv >= 3 && (p.sharp && p.d4 != 0)))
		p.f_width -= 2;
	if (p.baseconv == 2 && p.sharp)
		p.f_width--;
	return (p);
}
