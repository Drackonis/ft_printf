/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:28 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/28 14:26:23 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	const uint8_t	*c1;
	uint8_t			*c2;

	i = 0;
	c1 = src;
	c2 = dest;
	if (dest < src)
		while (i < (int)n)
		{
			c2[i] = c1[i];
			i++;
		}
	else
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			c2[i] = c1[i];
			i--;
		}
	}
	return (dest);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char *str1 = argv[1];
**	char *str2 = argv[2];
**	ft_memmove(str1, str2, 5);
**	printf("%s", str1);
**	return (0);
**}
*/
