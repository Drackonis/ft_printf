/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:18 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 17:21:49 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
/*
**int	main(int argc, char **argv)
**{
**	argc++;
**	ft_memdel((void**)argv[1]);
**	printf("%s", argv[1]);
**	return (0);
**}
*/
