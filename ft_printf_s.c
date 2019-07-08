/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:07:54 by dieroyer          #+#    #+#             */
/*   Updated: 2019/07/08 19:02:55 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_printf	char_conv(t_printf p)
{
	void	*v;

	p = initialize(p);
	p = is_modifier(p);
	p = ft_flag_modifier(p);
	v = va_arg(p.arg, void*);
	if (p.minus)
	{
		ft_putchar((char)v);
		ft_putwidth(p, -3);
	}
	else
	{
		ft_putwidth(p, -3);
		ft_putchar((char)v);
	}
	p.ret += (p.f_width > 1) ? p.f_width : 1;
	return (p);
}

t_printf	string_conv(t_printf p)
{
	p = initialize(p);
	p = is_modifier(p);
	if (p.lcount == 0)
	{
		p.str = va_arg(p.arg, char*);
		if (p.str == NULL)
		{
			ft_putwidth(p, -1);
			ft_putstr("(null)");
			p.ret += 6;
			return (p);
		}
		if ((p.prec_point == 0) || (p.f_precision > (int)ft_strlen((p.str))))
			p.f_precision = ft_strlen(p.str);
		if (p.is_width)
			p.ret += p.f_width;
		else
			p.ret += ft_strlen(p.str);
		ft_putstrpreci(p);
	}
	return (p);
}

t_printf	ft_putstrpreci(t_printf p)
{
	p = ft_flag_modifier(p);
	if (p.minus)
	{
		ft_putlstr(p.str, p.f_precision);
		ft_putwidth(p, -2);
	}
	else
	{
		ft_putwidth(p, -2);
		ft_putlstr(p.str, p.f_precision);
	}
	return (p);
}

t_printf	str_bonus(t_printf p)
{
	wchar_t	*v;

	p = is_modifier(p);
	v = va_arg(p.arg, wchar_t*);
	if (v != NULL)
	{
		ft_putstrw(v);
		p.ret += ft_wstrlen(v);
	}
	return (p);
}
