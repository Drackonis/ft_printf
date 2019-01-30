/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:01 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/24 18:17:06 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	const uint8_t	*str1;

	i = 0;
	str1 = str;
	while (i < n)
	{
		if (str1[i] == (unsigned char)c)
			return ((void*)str1 + i);
		i++;
	}
	return (NULL);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char *str1 = argv[1];
**	char *str2 = ft_memchr(str1, 42, 5);
**	printf("%s", str2);
**	return (0);
**}
*/
