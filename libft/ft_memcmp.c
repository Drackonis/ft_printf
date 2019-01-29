/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:06 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/16 14:03:49 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	i;
	const uint8_t	*str3;
	const uint8_t	*str4;

	i = 0;
	str3 = str1;
	str4 = str2;
	while (i < n)
	{
		if (str3[i] != str4[i])
			return (str3[i] - str4[i]);
		else
			i++;
	}
	return (0);
}
/*
**int	main(int argc, char **argv)
**{
**	int	i;
**
**	i = 0;
**	argc++;
**	char *str1 = argv[1];
**	char *str2 = argv[2];
**	i = ft_memcmp(str1, str2, 5);
**	printf("%d", i);
**	return (0);
**}
*/
