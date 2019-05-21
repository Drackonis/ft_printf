/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:07:54 by dieroyer          #+#    #+#             */
/*   Updated: 2019/05/21 20:20:36 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	char_conv(t_printf p)
{
	char	c;
	void	*v;
	int		i;

	p = is_modifier(p);
	i = p.i + ft_strlen(p.conv) + 1;
	if (p.format[i] == 'C' || (p.format[i] == 'c' && p.lcount == 1))
	{
		v = va_arg(p.arg, void*);
		p.ret++;
		ft_putchar((char)v);
	}
	else if (p.format[i] == 'c')
	{
		c = (char)va_arg(p.arg, int);
		p.ret++;
		ft_putchar(c);
	}
	return(p);
}

t_printf 	string_conv(t_printf p)
{
	char	*str;
	int		i;

	p = is_modifier(p);
	p = ft_flag_modifier(p);
	i = p.i + ft_strlen(p.conv) + 1;
	if (p.format[i] == 's' && p.format[i - 1] != 'l')
	{
		str = va_arg(p.arg, char*);
		if ((p.f_precision == 0 ) || (p.f_precision > (int)ft_strlen((str))))
			p.f_precision = ft_strlen(str);
		ft_putwidth(p, p.f_precision);
		ft_putlstr(str, p.f_precision);
		p.ret += ft_strlen(str);
	}
	else if (p.format[i] == 'S' || (p.format[i] == 's' && p.format[i - 1] == 'l'))
	{
		str_bonus(p);
	}
	return(p);
}

t_printf	str_bonus(t_printf p)
{

	void	*v;
	int		i;

	p = is_modifier(p);
	i = p.i + ft_strlen(p.conv) + 1;
	if (p.format[i] == 'S' || (p.format[i] == 's' && p.format[i - 1] == 'l'))
	{
		v = va_arg(p.arg, wchar_t*);
		if (v != NULL)
		{
			ft_putlwstr(v, p.f_precision);
			p.ret += ft_strlen(v);
		}
	}
	return (p);
}	

