/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:48:21 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 15:08:27 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		num;
	int		neg;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\v' ||\
			str[i] == '\n' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg -= 2;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if ((neg || str[i - 1] == '+') && (str[i] > '9' || str[i] < '0'))
		return (0);
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * neg);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	printf("%d\n", ft_atoi(argv[1]));
**	return (1);
**}
*/
