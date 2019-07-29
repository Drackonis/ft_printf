/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_hh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:17:33 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/29 15:34:26 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putunbr_hh_base(unsigned char nbr, char *base)
{
	int		size;
	int		n[100];
	int		i;
	int		len;

	i = 0;
	size = 0;
	len = 0;
	if (check_base(base))
	{
		while (base[size])
			size++;
		while (nbr > 0)
		{
			n[i] = nbr % size;
			nbr = nbr / size;
			i++;
		}
		while (--i >= 0)
		{
			ft_putchar(base[n[i]]);
			len++;
		}
	}
	return (len);
}

int			ft_putunbr_h_base(unsigned short nbr, char *base)
{
	int		size;
	int		n[100];
	int		i;
	int		len;

	i = 0;
	size = 0;
	len = 0;
	if (check_base(base))
	{
		while (base[size])
			size++;
		while (nbr > 0)
		{
			n[i] = nbr % size;
			nbr = nbr / size;
			i++;
		}
		while (--i >= 0)
		{
			ft_putchar(base[n[i]]);
			len++;
		}
	}
	return (len);
}

int			ft_unbrhhlen_base(unsigned short nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int			ft_unbrhlen_base(unsigned char nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

t_printf	get_arg_uh(t_printf p)
{
	if (p.hcount == 1)
	{
		p.d1 = (unsigned short)va_arg(p.arg, int);
		p.isneg = (p.d1 < 0) ? 1 : 0;
		p.numlen = ft_unbrhhlen_base(p.d1, p.current_base);
		p.d4 = (intmax_t)p.d1;
	}
	else if (p.hcount == 2)
	{
		p.d0 = (unsigned char)va_arg(p.arg, int);
		p.isneg = (p.d0 < 0) ? 1 : 0;
		p.numlen = ft_unbrhlen_base(p.d0, p.current_base);
		p.d4 = (intmax_t)p.d0;
	}
	return (p);
}
