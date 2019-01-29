/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:58:35 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 17:04:39 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	p = str;
	while (j < i)
	{
		*p++ = (*f)(j, s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	ft_strmapi(argv[1], ft_putchar);
**	return (0);
**}
*/
