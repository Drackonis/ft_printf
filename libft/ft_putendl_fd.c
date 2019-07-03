/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:36 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/03 17:03:49 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;
	char	b;

	i = 0;
	b = '\n';
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &b, 1);
}
/*
**int   main(int argc, char **argv)
**{
**      argc++;
**      ft_putendl_fd(argv[1]);
**      return (0);
**}
*/
