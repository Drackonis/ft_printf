/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:48:43 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/29 15:35:13 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_putunbr_ll_base(unsigned long long nbr, char *base)
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

int			ft_putunbr_base(unsigned int nbr, char *base)
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

int			ft_putunbr(unsigned long nbr, char *base)
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

void		ft_putnbr_intmax(intmax_t num)
{
	intmax_t	nb;
	int			t;
	char		c;

	t = 0;
	nb = num;
	if (nb >= 10)
	{
		t = nb % 10;
		c = t + 48;
		ft_putnbr_intmax(nb / 10);
	}
	else
		c = nb + 48;
	write(1, &c, 1);
}
