/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:56:36 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 12:36:37 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*ptr;
	unsigned char	*p;

	if (!(ptr = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	else
	{
		p = ptr;
		while (size--)
			*p++ = '\0';
		return (ptr);
	}
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	char	*str1 = argv[1];
**	str1 = ft_memalloc(5);
**	printf("%s", str1);
**	return (0);
**}
*/
