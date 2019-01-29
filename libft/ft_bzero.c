/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:55:56 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/16 14:02:11 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char *p;

	p = str;
	while (n--)
		*p++ = '\0';
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char *str1 = argv[1];
**	ft_bzero(str1, 5);
**	printf("%s", str1 + 4);
**	return (0);
**}
*/
