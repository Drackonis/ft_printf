/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:58:48 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/24 18:16:22 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*s;
	size_t		i;

	i = 0;
	s = dst;
	while (*src != '\0' && ++i <= len)
		*(dst++) = *(src++);
	while (++i <= len)
		*(dst++) = '\0';
	return (s);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char *str1 = argv[1];
**	char *str2 = argv[2];
**	ft_strncpy(str1,str2,5);
**	printf("%s", str1);
**	return (0);
**}
*/
