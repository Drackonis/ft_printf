/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:44:19 by dieroyer          #+#    #+#             */
/*   Updated: 2019/07/29 16:02:39 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	ft_flag_modifier(t_printf p)
{
	int		i;

	p.minus = 0;
	p.mput = 0;
	p.plus = 0;
	p.space = 0;
	i = 0;
	while (i < p.is_flag)
	{
		if (p.conv[i] == '-')
			p.minus++;
		else if (p.conv[i] == '+')
			p.plus++;
		else if (p.conv[i] == ' ')
			p.space++;
		i++;
	}
	return (p);
}

t_printf	ft_putwidth(t_printf p, int len)
{
	int		width;

	p = is_modifier(p);
	width = p.f_width;
	if (len == -2 || len == -1)
	{
		if (p.is_precision && len == -2 && p.strerror != 1
				&& p.f_precision < (int)ft_strlen(p.str))
			width -= p.f_precision;
		else if (len == -1)
			width -= 6;
		else if ((width >= (int)ft_strlen(p.str)
					|| p.f_precision > (int)ft_strlen(p.str)) && len == -2)
			width -= (int)ft_strlen(p.str);
		else if (width < (int)ft_strlen(p.str) && len == -2)
			width = 0;
	}
	else if (len == -3)
		width -= 1;
	while (width > 0)
	{
		ft_putchar(' ');
		width--;
	}
	return (p);
}

t_printf	ft_getconv(t_printf p, int base, int len)
{
	p.baseconv = base;
	p = initialize(p);
	p = is_modifier(p);
	p = flag_modifier(p);
	p = range_sharp(p);
	p = float_conv(p);
	p = error_f(p);
	p = put_start_space2(p);
	len = 0;
	if (!p.minus)
	{
		p = put_mp(p);
		p = put_width(p);
		p = put_nbr_modified(p);
	}
	else
	{
		p = put_mp(p);
		p = put_nbr_modified(p);
		p = put_width(p);
	}
	p.c = 0;
	while (p.c < p.diff)
		p.c++;
	return (p);
}

t_printf	put_start_space2(t_printf p)
{
	if (p.space && !p.plus && p.isneg == 0)
	{
		ft_putchar(' ');
		p.ret++;
	}
	return (p);
}
