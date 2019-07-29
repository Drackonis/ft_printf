/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:09:54 by dieroyer          #+#    #+#             */
/*   Updated: 2019/07/29 15:34:35 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reverse(char *str, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

intmax_t	ft_inttostr(intmax_t x, char *str, int d)
{
	t_printf	p;
	intmax_t	i;

	i = 0;
	if (x < 0)
	{
		x *= -1;
		p.strf[0] = '-';
	}
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

t_printf	ft_printf_blf(long double n, char *res, int afterpoint, t_printf p)
{
	long double	fpart;
	intmax_t	i;

	p.ipart = (intmax_t)n;
	fpart = n - (long double)p.ipart;
	if (p.ipart < 0)
		p.ipart = p.ipart * -1;
	if ((fpart >= 0.5 || fpart < -0.5) && afterpoint == 0)
		p.ipart += 1;
	if (p.ipart != 0)
		i = ft_inttostr(p.ipart, res, 0);
	else
		i = ft_inttostr(p.ipart, res, 1);
	if (fpart < 0)
		fpart = fpart * -1;
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_power2(10, afterpoint);
		ft_inttostr((intmax_t)fpart, res + i + 1, afterpoint);
	}
	if (afterpoint == 0 && p.sharp)
		res[i] = '.';
	return (p);
}

t_printf	ft_printf_lf(double n, char *res, int afterpoint, t_printf p)
{
	double		fpart;
	intmax_t	i;

	p.ipart = (intmax_t)n;
	fpart = n - (double)p.ipart;
	if (p.ipart < 0)
		p.ipart = p.ipart * -1;
	if ((fpart > 0.5 || fpart < -0.5) && afterpoint == 0)
		p.ipart += 1;
	if (p.ipart != 0)
		i = ft_inttostr(p.ipart, res, 0);
	else
		i = ft_inttostr(p.ipart, res, 1);
	fpart = (fpart < 0) ? fpart * -1 : fpart * 1;
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_power2(10, afterpoint) + 0.5;
		ft_inttostr((intmax_t)fpart, res + i + 1, afterpoint);
	}
	if (afterpoint == 0 && p.sharp)
		res[i] = '.';
	return (p);
}
