
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

/*int	nbrlen(intmax_t nbr)
{
	int	l;

	l = 0;
	while (nbr > 9)
	{
		nbr = nbr/10;
		l++;
	}
	l++;
	return(l);
}


void	test(intmax_t i)
{
	i*=2;
}*/

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	a;
	int	*b;
	int	x;
	unsigned char c;
	i = 10;
	j = 10;
	a = 5;
	b = &a;
	x = (int) &i;
	printf("10.1 : %p | 10.2 : %p | 5 : %p | b : %p\n", &i, &j, &a, b);
	ft_putchar(*(1 + (unsigned char*) &x));
	ft_putchar(*(( unsigned char *) &x));



	/*int i = atoi(argv[1]);
	signed char j;
	int k = 0;
	int l = i;
	int m = 0;
	intmax_t n = 9223372036854775807;

	j = (signed char)i;
	k = (int)j;
	printf ("i : %d| j : %d | k : %d | l : %d\n", i, j, k, l);
	test(l);
	printf ("l : %d\n", l);
	m = nbrlen(n);
	printf ("n : %lld | m : %d", n, m);*/
	return(0);
}
