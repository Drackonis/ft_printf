/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:07:54 by dieroyer          #+#    #+#             */
/*   Updated: 2019/06/07 12:36:29 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

t_printf	char_conv(t_printf p)
{
	void	*v;
	int		i;

	p = initialize(p);
	p = is_modifier(p);
	p = ft_flag_modifier(p);
	i = p.i + ft_strlen(p.conv) + 1;
	if ((p.format[i] == 'C') || (p.format[i] == 'c'))
	{
		v = va_arg(p.arg, void*);
		if (p.minus)
		{
			ft_putchar((char)v);
			ft_putwidth(p, 1);
		}
		else
		{
			ft_putwidth(p, 1);
			ft_putchar((char)v);
		}
		p.ret += (p.f_width > 1) ? p.f_width : 1;
	}
	return (p);
}

t_printf	string_conv(t_printf p)
{
	int		i;

	p = initialize(p);
	p = is_modifier(p);
	i = p.i + ft_strlen(p.conv) + 1;
	if (p.format[i] == 's' && p.format[i - 1] != 'l')
	{
		p.str = va_arg(p.arg, char*);
		if (p.str == NULL)
		{
			ft_putstr("(null)");
			p.ret += 6;
			return (p);
		}
		if ((p.f_precision == 0) || (p.f_precision > (int)ft_strlen((p.str))))
			p.f_precision = ft_strlen(p.str);
		if (p.f_width > (int)ft_strlen(p.str))
			p.ret += p.f_width;
		else if (p.f_precision < (int)ft_strlen(p.str))
			p.ret += p.f_precision;
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
		ft_putwidth(p, p.f_precision);
	}
	else
	{
		ft_putwidth(p, p.f_precision);
		ft_putlstr(p.str, p.f_precision);
	}
	return (p);
}

t_printf	str_bonus(t_printf p)
{
	wchar_t	*v;
	int		i;

	p = is_modifier(p);
	i = p.i + ft_strlen(p.conv) + 1;
	if ((p.format[i]) == 'S' || (p.format[p.i] == 's'
				&& p.format[i - 1] == 'l'))
	{
		v = va_arg(p.arg, wchar_t*);
		if (v != NULL)
		{
			ft_putstrw(v);
			p.ret += ft_wstrlen(v);
		}
	}
	return (p);
}
