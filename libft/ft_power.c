/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:32:15 by dieroyer          #+#    #+#             */
/*   Updated: 2019/05/13 18:32:34 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int x, unsigned int y)
{
	int temp;

	if (y == 0)
		return (1);
	temp = ft_power(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (x * temp * temp);
}
