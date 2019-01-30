/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:59:07 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/28 14:32:47 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s2[j] == s1[i + j] && i + j < n)
			{
				if (s2[j + 1] == '\0')
					return ((char *)s1 + i);
				else
					j++;
			}
		}
		i++;
	}
	return (NULL);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char *str1 = argv[1];
**	char *str2 = argv[2];
**	char *str3 = ft_strnstr(str1, str2, 8);
**	char *str4 = strnstr(str1, str2, 3);
**	printf("%s\n%s\n", str3, str4);
**	return (0);
**}
*/
