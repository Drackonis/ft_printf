/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_lh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:02:08 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/29 15:35:07 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			printf_base_hh_nbr(t_printf p)
{
	if (p.hcount == 1)
	{
		if (p.baseconv == 1)
			ft_putunbr_h_base(p.d1, "0123456789");
		else if (p.baseconv == 2)
			ft_putunbr_h_base(p.d1, "01234567");
		else if (p.baseconv == 3)
			ft_putunbr_h_base(p.d1, "0123456789abcdef");
		else if (p.baseconv == 4)
			ft_putunbr_h_base(p.d1, "0123456789ABCDEF");
	}
	else
	{
		if (p.baseconv == 1)
			ft_putunbr_hh_base(p.d0, "0123456789");
		else if (p.baseconv == 2)
			ft_putunbr_hh_base(p.d0, "01234567");
		else if (p.baseconv == 3)
			ft_putunbr_hh_base(p.d0, "0123456789abcdef");
		else if (p.baseconv == 4)
			ft_putunbr_hh_base(p.d0, "0123456789ABCDEF");
	}
}

void			printf_base_ll_nbr(t_printf p)
{
	if (p.d8 != 0 || (p.d8 == 0 && p.d4 == 0 && p.d3 == 0))
	{
		if (p.baseconv == 1)
			ft_putunbr_ll_base(p.d8, "0123456789");
		else if (p.baseconv == 2)
			ft_putunbr_ll_base(p.d8, "01234567");
		else if (p.baseconv == 3)
			ft_putunbr_ll_base(p.d8, "0123456789abcdef");
		else if (p.baseconv == 4)
			ft_putunbr_ll_base(p.d8, "0123456789ABCDEF");
	}
	else
	{
		if (p.baseconv == 1)
			ft_putunbr_ll_base(p.d3, "0123456789");
		else if (p.baseconv == 2)
			ft_putunbr_ll_base(p.d3, "01234567");
		else if (p.baseconv == 3)
			ft_putunbr_ll_base(p.d3, "0123456789abcdef");
		else if (p.baseconv == 4)
			ft_putunbr_ll_base(p.d3, "0123456789ABCDEF");
	}
}

t_printf		ft_llmin(t_printf p)
{
	ft_putunbr_ll_base(p.d4, "0123456789");
	p.ret = 20;
	if (p.d4 >= 0)
		p.ret--;
	return (p);
}

void			ft_printf_base_select(t_printf p)
{
	if (p.lcount > 0)
		printf_base_ll_nbr(p);
	else if (p.hcount > 0)
		printf_base_hh_nbr(p);
}
