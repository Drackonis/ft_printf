/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:58:20 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 13:51:08 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *c1, const char *c2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	l;

	k = 0;
	l = 0;
	while (c1[k])
		k++;
	while (c2[l])
		l++;
	i = k;
	if (n - 1 < i || n <= 0)
		return (n + l);
	j = 0;
	while (c2[j] && i + j < n - 1)
	{
		c1[i + j] = c2[j];
		j++;
	}
	c1[i + j] = '\0';
	return (k + l);
}
/*
**int		main(int argc, char **argv)
**{
**	int	i;
**
**	argc++;
**	i = ft_strlcat(argv[1], argv[2], 5);
**	printf("%d", i);
**	return 0;
**}
*/
