/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:09:54 by dieroyer          #+#    #+#             */
/*   Updated: 2019/07/02 20:21:58 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <math.h>
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

int		ft_inttostr(intmax_t x, char *str, int d)
{
	t_printf	p;
	int			i;

	i = 0;
	printf("x = %jd\n", x);
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

/*void	ft_printf_f(double n, char *res, int afterpoint)
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
}*/

void	ft_printf_blf(long double n, char *res, int afterpoint)
{
	intmax_t	ipart;
	long double	fpart;
	intmax_t	i;

	ipart = (intmax_t)n;
	fpart = n - (long double)ipart;
	i = ft_inttostr(ipart, res, 0);
	if (fpart < 0)
		fpart = fpart * -1;
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_power2(10, afterpoint);
		ft_inttostr((intmax_t)fpart, res + i + 1, afterpoint);
	}
}

t_printf	ft_printf_lf(double n, char *res, int afterpoint, t_printf p)
{
	intmax_t	ipart;
	double		fpart;
	intmax_t	i;

	printf("afterpoint %d\n", afterpoint);
	ipart = (intmax_t)n;
	fpart = n - (double)ipart;
	if (ipart < 0)
	{
		ipart = ipart * -1;
		if (fpart < 0.5)
			ipart += 1;
		p.strf[0] = '-';
	}
	i = ft_inttostr(ipart, res, 0);
	if (fpart < 0)
		fpart = fpart * -1;
	if (afterpoint != 0)
	{
		res[i] = '.';
		printf("fpart 0 = %f\n", fpart);
		fpart = fpart * ft_power2(10, afterpoint) + 0.5;
		printf("fpart = %jd\n", (intmax_t)fpart);
		ft_inttostr((intmax_t)fpart, res + i + 1, afterpoint);
	}
	if (afterpoint == 0 && p.sharp)
		res[i] = '.';
	return (p);
}
