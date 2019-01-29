/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:56:31 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 17:08:55 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_leneg(int n, int *neg, int *j)
{
	unsigned int	i;
	unsigned int	x;

	*j = 1;
	*neg = 0;
	if (n < 0)
	{
		*neg += 1;
		*j += 1;
		x = n * (-1);
	}
	else
		x = n;
	i = x;
	while (i > 9)
	{
		i /= 10;
		*j += 1;
	}
	return (x);
}

char		*ft_itoa(int n)
{
	unsigned int		i;
	int					j;
	char				t;
	int					neg;
	char				*str;

	i = ft_leneg(n, &neg, &j);
	if (!(str = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	str[j] = '\0';
	while (i > 9)
	{
		j--;
		t = i % 10;
		str[j] = t + '0';
		i /= 10;
	}
	j--;
	str[j--] = i + '0';
	if (neg)
		str[j] = '-';
	return (str);
}
/*
**int	main()
**{
**	int i = -2147483647 - 1;
**	char *str1 = ft_itoa(i);
**	printf("\n|\n%s\n|\n", str1);
**	return (0);
**}
*/
