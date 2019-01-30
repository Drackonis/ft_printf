/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:10 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/16 14:03:57 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	uint8_t			*c1;
	const uint8_t	*c2;

	i = 0;
	c1 = dest;
	c2 = src;
	while (i < n)
	{
		c1[i] = c2[i];
		i++;
	}
	return (dest);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char *str1 = argv[1];
**	char *str2 = argv[2];
**	ft_memcpy(str1, str2, 5);
**	printf("%s", str1);
**	return (0);
**}
*/
