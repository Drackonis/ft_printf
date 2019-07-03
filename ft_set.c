/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:22:34 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/03 16:55:39 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		get_arg(t_printf p)
{
	int			current_base;

	current_base = 10;
	if (p.baseconv == -2)
		p = set_perc_conv(p);
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
	if (p.baseconv == 0 && p.prec_point && p.d4 == 0 && p.f_precision == 0)
		p.numlen = 0;
	p.ret += p.numlen;
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

t_printf		is_modifier(t_printf p)
{
	char	c;
	int		number;

	number = 0;
	while (p.c < p.diff)
	{
		c = p.conv[p.c];
		p = get_start_flags(p, c, number);
		if (c == '.')
			p.prec_point++;
		else if (((c >= '1' && c <= '9') || (c == '0' && number)))
		{
			number = 1;
			p = get_is_wipr(p);
		}
		else
			p = get_hll(p, c);
		p.c++;
	}
	p = get_wipr(p);
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
