/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:09:54 by dieroyer          #+#    #+#             */
/*   Updated: 2019/05/28 18:27:03 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	reverse(char *str, int len)
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

int		ft_inttostr(int x, char *str, int d)
{
	t_printf	p;
	int			i;
	int			neg;

	i = 0;
	neg = 0;
	if (x < 0)
	{
		x *= -1;
		neg = 1;
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

void	ft_printf_f(float n, char *res, int afterpoint)
{
	intmax_t	ipart;
	float		fpart;
	intmax_t	i;

	ipart = (intmax_t)n;
	fpart = n - (float)ipart;
	i = ft_inttostr(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_power(10, afterpoint) + 0.5;
		ft_inttostr((intmax_t)fpart, res + i + 1, afterpoint);
	}
}

void	ft_printf_blf(long double n, char *res, int afterpoint)
{
	intmax_t	ipart;
	long double	fpart;
	intmax_t	i;

	ipart = (intmax_t)n;
	fpart = n - (long double)ipart;
	i = ft_inttostr(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_power(10, afterpoint) + 0.5;
		ft_inttostr((intmax_t)fpart, res + i + 1, afterpoint);
	}
}

void	ft_printf_lf(double n, char *res, int afterpoint)
{
	intmax_t	ipart;
	double		fpart;
	intmax_t	i;

	ipart = (intmax_t)n;
	fpart = n - (double)ipart;
	i = ft_inttostr(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_power(10, afterpoint) + 0.5;
		ft_inttostr((intmax_t)fpart, res + i + 1, afterpoint);
	}
}
