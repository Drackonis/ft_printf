/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:39 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/16 14:04:37 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strcat(char *c1, const char *c2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (c1[i])
		i++;
	while (c2[j])
	{
		c1[i + j] = c2[j];
		j++;
	}
	c1[i + j] = '\0';
	return (c1);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char *str1 = argv[1];
**	char *str2 = argv[2];
**	ft_strcat(str1, str2);
**	printf("%s", str1);
**	return (0);
**}
*/
