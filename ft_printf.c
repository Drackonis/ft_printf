/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:59:58 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/29 15:33:59 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		do_conv(t_printf p, t_printf ptmp)
{
	if (p.format[p.i] == 'c' || p.format[p.i] == 'C')
		p = char_conv(ptmp);
	else if (p.format[p.i] == 's')
		p = string_conv(ptmp);
	else if (p.format[p.i] == 'S'
			|| (p.format[p.i] == 's' && p.format[p.i - 1] == 'l'))
		p = str_bonus(ptmp);
	else if (p.format[p.i] == 'p')
		p = call_conv_idx(ptmp, 5);
	else if (p.format[p.i] == 'd' || p.format[p.i] == 'i')
		p = call_conv_idx(ptmp, 0);
	else if (p.format[p.i] == 'o')
		p = call_conv_idx(ptmp, 2);
	else if (p.format[p.i] == 'u')
		p = call_conv_idx(ptmp, 1);
	else if (p.format[p.i] == 'x')
		p = call_conv_idx(ptmp, 3);
	else if (p.format[p.i] == 'X')
		p = call_conv_idx(ptmp, 4);
	else if (p.format[p.i] == 'f')
		p = ft_getconv(ptmp, -1, 0);
	else if (p.format[p.i] == '%')
		p = call_conv_idx(ptmp, -2);
	return (p);
}

t_printf		call_conv(t_printf p, t_printf ptmp)
{
	ptmp = init_call_conv(ptmp, p);
	p = do_conv(p, ptmp);
	p.i += ptmp.diff + 1;
	return (p);
}

t_printf		init_call_conv(t_printf ptmp, t_printf p)
{
	int			i;

	i = 0;
	ptmp.diff = (p.i - 1) - ptmp.i;
	while (i < ptmp.diff)
	{
		ptmp.conv[i] = p.conv[i];
		i++;
	}
	return (ptmp);
}

t_printf		check_conv(t_printf ptmp)
{
	t_printf p;

	p = ptmp;
	p.i++;
	p.c = 0;
	while (p.format[p.i] != 'c' &&\
			p.format[p.i] != 's' &&\
			p.format[p.i] != 'p' &&\
			p.format[p.i] != 'd' &&\
			p.format[p.i] != 'i' &&\
			p.format[p.i] != 'o' &&\
			p.format[p.i] != 'u' &&\
			p.format[p.i] != 'x' &&\
			p.format[p.i] != 'X' &&\
			p.format[p.i] != 'f' &&\
			p.format[p.i] != 'S' &&\
			p.format[p.i] != '%')
	{
		p.conv[p.c] = p.format[p.i];
		p.c++;
		p.i++;
	}
	p = call_conv(p, ptmp);
	p.i++;
	return (p);
}

int				ft_printf(const char *format, ...)
{
	t_printf	p;

	p.i = 0;
	p.c = 0;
	p.ret = 0;
	p.baseconv = 0;
	p.format = ft_strdup(format);
	if (!check_error(p))
		return (-1);
	va_start(p.arg, format);
	while (p.format[p.i])
	{
		if (p.format[p.i] == '%')
			p = check_conv(p);
		else
		{
			write(1, &p.format[p.i], 1);
			p.ret++;
			p.i++;
		}
	}
	free(p.format);
	va_end(p.arg);
	return (p.ret);
}
