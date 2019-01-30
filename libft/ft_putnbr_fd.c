/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:36 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 13:01:49 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				t;
	char			c;

	t = 0;
	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		nb = n * (-1);
	}
	else
		nb = n;
	if (nb >= 10)
	{
		t = nb % 10;
		c = t + 48;
		ft_putnbr_fd(nb / 10, fd);
	}
	else
		c = nb + 48;
	write(fd, &c, 1);
}
/*
**int   main(void)
**{
**      ft_putnbr_fd(-12345);
**      return (0);
**}
*/
