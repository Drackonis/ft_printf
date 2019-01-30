/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:35:53 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 17:24:07 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_putendl(char const *s)
{
	int		i;
	char	b;

	if (!s)
		return ;
	i = 0;
	b = '\n';
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, &b, 1);
}
/*
**int   main(int argc, char **argv)
**{
**      argc++;
**      ft_putendl(argv[1]);
**      return (0);
**}
*/
