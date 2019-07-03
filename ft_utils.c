/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/03 16:53:11 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_ctoi(char c)
{
	int			i;

	i = c - '0';
	return (i);
}

int				cmp_flag(char c)
{
	if (c == ' ' || c == '+' || c == '#' || c == '-' || c == '0')
		return (1);
	else
		return (0);
}

int				cmp_nb(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == '.')
		return (2);
	else
		return (0);
}

int				cmp_lh(char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	else
		return (0);
}
