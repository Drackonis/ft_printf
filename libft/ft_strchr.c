/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:41 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/16 14:04:44 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		j;
	char	*s1;

	j = 0;
	s1 = (char*)s;
	while (s1[j])
	{
		if (s1[j] == c)
			return (&s1[j]);
		j++;
	}
	if (s1[j] == c)
		return (&s1[j]);
	return (NULL);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char *str1 = argv[1];
**	str1 = ft_strchr(str1, (int)'x');
**	printf("%s", str1);
**	return (0);
**}
*/
