/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:51:40 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/16 14:04:19 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *p;

	p = str;
	while (n--)
		*p++ = (unsigned char)c;
	return (str);
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char *str1 = argv[1];
**	ft_memset(str1, 42, 5);
**	printf(str1);
**	return (0);
**}
*/
