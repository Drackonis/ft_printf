/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:09:54 by dieroyer          #+#    #+#             */
/*   Updated: 2019/05/13 19:19:40 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

static void	reverse(char *str, int len)
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

static int		ft_inttostr(int x, char *str, int d)
{
	int i;

	i = 0;
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
	int		ipart;
	float	fpart;
	int		i;

	ipart = (int)n;
	fpart = n - (float)ipart;
	i = ft_inttostr(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_power(10, afterpoint) + 0.5;
		ft_inttostr((int)fpart, res + i + 1, afterpoint);
	}
}

void	ft_printf_blf(long double n, char *res, int afterpoint)
{
	int		ipart;
	long double	fpart;
	int		i;

	ipart = (int)n;
	fpart = n - (long double)ipart;
	i = ft_inttostr(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_power(10, afterpoint) + 0.5;
		ft_inttostr((int)fpart, res + i + 1, afterpoint);
	}
}

void	ft_printf_lf(double n, char *res, int afterpoint)
{
	int		ipart;
	double	fpart;
	int		i;

	ipart = (int)n;
	fpart = n - (double)ipart;
	i = ft_inttostr(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_power(10, afterpoint) + 0.5;
		ft_inttostr((int)fpart, res + i + 1, afterpoint);
	}
}
