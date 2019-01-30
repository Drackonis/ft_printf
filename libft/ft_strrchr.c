/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:59:19 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 13:54:34 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;
	char	*s1;

	j = 0;
	s1 = (char*)s;
	while (s1[j])
		j++;
	j++;
	while (j-- >= 0)
		if (s1[j] == c)
			return (&s1[j]);
	return (NULL);
}
/*
**int	main(int argc, char **argv)
**{
**	char *str1 = argv[1];
**	argc++;
**	str1 = ft_strrchr(str1, (int)'x');
**	printf("%s", str1);
**	return (0);
**}
*/
