/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:56:17 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/16 14:02:31 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
**int	main(void)
**{
**	int	i;
**	int	j;
**	i = 0;
**	while (i <= 127)
**	{
**		j = ft_isalpha(i);
**		printf("|%d|%c|\n", j, i);
**		i++;
**	}
**	return (1);
**}
*/
