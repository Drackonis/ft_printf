/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/08 18:30:38 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nbr_conv(t_printf p, int start, int val)
{
	int			i;
	int			nbr;
	int			puissance;

	i = 0;
	nbr = 0;
	puissance = 1;
	while (i < val)
	{
		nbr += puissance * (ft_ctoi(p.conv[start - i]));
		puissance *= 10;
		i++;
	}
	return (nbr);
}

int			ft_nbrlen(intmax_t n)
{
	int		l;

	l = 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	l++;
	return (l);
}

int			ft_nbrhlen_base(intmax_t nbr, int base)
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

int			ft_nbrulen_base(unsigned long nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int			ft_nbrlen_base(unsigned int nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
