/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:44:19 by dieroyer          #+#    #+#             */
/*   Updated: 2019/05/27 17:01:52 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	ft_flag_modifier(t_printf p)
{
	int	i;

	p.minus = 0;
	p.mput = 0;
	p.plus = 0;
	p.space = 0;
	p.sharp = 0;
	i = 0;
	while (i < p.is_flag)
	{
		if (p.conv[i] == '-')
			p.minus++;
		else if (p.conv[i] == '+')
			p.plus++;
		else if (p.conv[i] == ' ')
			p.space++;
		else if (p.conv[i] == '#')
			p.sharp++;
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
	width = p.f_width - len;
	//printf("\nwidth = %d\n", width);
	while (width > 0)
	{
		ft_putchar(' ');
		width--;
	}
	return (p);
}

t_printf	ft_getconv(t_printf p, int base, int len)
{
	p = is_modifier(p);
	p = flag_modifier(p);
	p.baseconv = base;
	p.numlen = len;
	
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
	{
		p.c++;
	}
	return(p);
}
