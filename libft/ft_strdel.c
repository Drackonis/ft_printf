/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:58:01 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 16:27:58 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_strdel(char **as)
{
	if (!as || as == '\0')
		return ;
	if (*as)
	{
		free(*as);
		*as = NULL;
	}
}
/*
**int main(void)
**{
**	char *arg;
**	if(!(arg = malloc(sizeof(char) * 6)))
**		return (0);
**	arg = "check\0";
**	ft_strdel(&arg);
**	printf("%s", arg);
**	return 0;
**}
*/
