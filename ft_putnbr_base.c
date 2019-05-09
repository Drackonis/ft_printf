#include "ft_printf.h"

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	if (base[0] == '\0' || base[1] == '\0')
		return(0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return(0);
		if (base[i] < 32 || base[i] > 126)
			return(0);
		while (base[j])
		{
			if (base[i] == base[j])
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}

int	ft_nbrlen_base(unsigned int nbr, int base)
{
	int	i;
	int	len;

	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return(len);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	size;
	int	n[100];
	int	i;
	int	len;

	i = 0;
	size = 0;
	len = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
			len++;
		}
		while (base[size])
			size++;
		while (nbr > 0)
		{
			n[i] = nbr % size;
			nbr = nbr / size;
			i++;
		}
		while (--i >= 0)
		{
			ft_putchar(base[n[i]]);
			len++;
		}
	}
	return (len);
}
