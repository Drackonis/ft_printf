/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/25 18:32:04 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		intialize2(t_printf p)
{
	p.current_base = 10;
	p.c = 0;
	p.d = 0;
	p.d0 = 0;
	p.d1 = 0;
	p.d2 = 0;
	p.d3 = 0;
	p.d4 = 0;
	p.d5 = 0;
	p.d6 = 0;
	p.d7 = 0;
	p.d8 = 0;
	p.strerror = 0;
	return (p);
}

t_printf		initialize(t_printf p)
{
	p.is_flag = 0;
	p.zero = 0;
	p.is_width = 0;
	p.is_precision = 0;
	p.hcount = 0;
	p.lcount = 0;
	p.f_precision = 0;
	p.f_width = 0;
	p.blcount = 0;
	p.prec_point = 0;
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

t_printf		set_perc_conv(t_printf p)
{
	p.numlen = 1;
	p.f_precision = 0;
	return (p);
}

t_printf		call_conv_idx(t_printf p, int i)
{
	p.baseconv = i;
	p = get_conv(p);
	return (p);
}
