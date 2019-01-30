/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:58:29 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 17:02:22 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		*p++ = (*f)(s[j]);
		j++;
	}
	return (str);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char (*f) = ft_do_something(char);
**	ft_strmap(argv[1], (*f));
**	return (0);
**}
*/
