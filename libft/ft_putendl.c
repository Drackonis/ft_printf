/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:35:53 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/03 17:04:13 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <unistd.h>

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
