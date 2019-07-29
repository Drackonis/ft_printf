/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/29 15:33:10 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_error(void)
{
	write(1, "Error input format : %[flags][width][.precision]", 49);
	write(1, "[length]specifier\n", 18);
}

int				chech_is_conv(char c)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p' || c == 'd'\
			|| c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X'\
			|| c == 'f' || c == '%')
		return (1);
	else if (!c)
	{
		print_error();
		return (0);
	}
	else
	{
		print_error();
		return (0);
	}
}

int				along_format(t_printf p, int i)
{
	while (p.format[i] && cmp_flag(p.format[i]))
		i++;
	while (p.format[i] && cmp_nb(p.format[i]))
		i++;
	while (p.format[i] && cmp_lh(p.format[i]))
		i++;
	return (i);
}

int				check_error(t_printf p)
{
	int			i;

	i = 0;
	if (p.format == NULL)
	{
		free(p.format);
		return (0);
	}
	while (p.format[i])
	{
		if (p.format[i] == '%')
		{
			i++;
			i = along_format(p, i);
			if (!chech_is_conv(p.format[i]))
			{
				free(p.format);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
