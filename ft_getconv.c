/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:44:19 by dieroyer          #+#    #+#             */
/*   Updated: 2019/07/08 19:04:30 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_printf	ft_flag_modifier(t_printf p)
{
	int	i;

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
	if (p.space && !p.plus && p.d >= 0)
	{
		ft_putchar(' ');
		p.ret++;
	}
	return (p);
}

t_printf	ft_putwidth(t_printf p, int len)
{
	int		width;

	p = is_modifier(p);
	width = p.f_width;
	if (p.is_precision && len == -2)
		width -= p.f_precision;
	else if (len == -1)
		width -= 6;
	else if (width >= (int)ft_strlen(p.str) && len == -2)
		width -= (int)ft_strlen(p.str);
	else if (width < (int)ft_strlen(p.str) && len == -2)
		width = 0;
	if (len == -3)
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
	p = initialize(p);
	p = is_modifier(p);
	p = flag_modifier(p);
	p = range_sharp(p);
	p = put_start_space(p);
	p = float_conv(p);
	p = error_f(p);
	p.baseconv = base;
	len = 0;
	if (!p.minus)
	{
		p = put_width(p);
		p = put_nbr_modified(p);
	}
	else
	{
		p = put_nbr_modified(p);
		p = put_width(p);
	}
	p.c = 0;
	while (p.c < p.diff)
		p.c++;
	return (p);
}
