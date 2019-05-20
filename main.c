/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:44:08 by dieroyer          #+#    #+#             */
/*   Updated: 2019/05/20 16:12:00 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <float.h>

int		main(int ac, char **av)
{	t_printf p;
	float ff =  123456789.123123;
	printf("PRINTF OG = %f\n", FLT_MAX);
	printf("PRINT OG2 = %f\n", ff);
	ft_printf("MY PRINTF = %f\n", ff);
}

