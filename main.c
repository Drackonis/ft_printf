/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:44:08 by dieroyer          #+#    #+#             */
/*   Updated: 2019/06/25 15:30:46 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <float.h>

int		main(int ac, char **av)
{
	int ret = 0;
	int true_ret = 0;
	ac++;
	printf("True printf :\n");

	//CHAR TESTS_______________________
	/*
	true_ret = printf(av[1], (char)av[2][0], (char)av[3][0]);
	printf("\n");
	write(1, "My printf :", 11);
	printf("\n");
	ret = ft_printf(av[1], (char)av[2][0], (char)av[3][0]);
	*/
	//INT TESTS_______________________

	true_ret = printf(av[1], ft_atoi(av[2]));
	printf("\n");
	write(1, "My printf :", 11);
	printf("\n");
	ret = ft_printf(av[1], ft_atoi(av[2]));

	/*true_ret = printf(av[1], ft_atoi(av[2]), ft_atoi(av[3]));
	printf("\n");
	write(1, "My printf :", 11);
	printf("\n");
	ret = ft_printf(av[1], ft_atoi(av[2]), ft_atoi(av[3]));
	*/
	
	//FLOAT TESTS_____________________
	/*
	t_printf p;
	float ff =  123456789.123123;
	//printf("PRINTF OG = %f\n", FLT_MAX);
	printf(av[1], ff);
	printf("\n");
	ft_printf(av[1], ff);
	*/
	printf("\nTrue ret = %d\nMy ret = %d\n", true_ret, ret);
	return(0);
}

