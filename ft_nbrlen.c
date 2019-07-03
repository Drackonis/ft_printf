/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/02 20:22:34 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

