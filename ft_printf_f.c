/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieroyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:09:54 by dieroyer          #+#    #+#             */
/*   Updated: 2019/05/09 17:29:09 by dieroyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reverse(char *str, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int		ft_inttostr(int x, char *str, int d)
{
	int i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

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

void	ft_printf_f(float n, char *res, int afterpoint)
{
	int		ipart;
	float	fpart;
	int		i;

	ipart = (int)n;
	fpart = n - (float)ipart;
	i = ft_inttostr(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_power(10, afterpoint) + 0.5;
		ft_inttostr((int)fpart, res + i + 1, afterpoint);
	}
}
