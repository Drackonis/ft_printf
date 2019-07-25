/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:53:14 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/25 15:04:08 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i])
		i++;
	if (!(c = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	while (j < i)
	{
		c[j] = src[j];
		j++;
	}
	c[j] = '\0';
	return (c);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char *str1 = argv[1];
**	char *str2 = ft_strdup(str1);
**	printf("%s", str2);
**	return (0);
**}
*/
