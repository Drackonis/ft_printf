/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:35:12 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/03 17:04:34 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;
	int				t;
	char			c;

	t = 0;
	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		nb = n * (-1);
	}
	else
		nb = n;
	if (nb >= 10)
	{
		t = nb % 10;
		c = t + 48;
		ft_putnbr(nb / 10);
	}
	else
		c = nb + 48;
	write(1, &c, 1);
}
/*
**int	main(void)
**{
**	ft_putnbr(-2147483647 - 1);
**	return (0);
**}
*/
