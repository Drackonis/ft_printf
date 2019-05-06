#include <stdio.h>

void reverse(char *str, int len) 
{ 
	int i=0, j=len-1, temp; 
	while (i<j) 
	{ 
		temp = str[i]; 
		str[i] = str[j]; 
		str[j] = temp; 
		i++; j--; 
	} 
}

int intToStr(int x, char str[], int d) 
{ 
	int i = 0; 
	while (x) 
	{ 
		str[i++] = (x%10) + '0'; 
		x = x/10; 
	} 

	while (i < d) 
		str[i++] = '0'; 

	reverse(str, i); 
	str[i] = '\0'; 
	return i; 
}

int ft_power(int x, unsigned int y) 
{ 
	int temp; 
	if( y == 0) 
		return 1; 
	temp = ft_power(x, y/2); 
	if (y%2 == 0) 
		return temp*temp; 
	else
		return x*temp*temp; 
} 

void	ftoa(float n, char *res, int afterpoint)
{
	int	ipart = (int)n;

	float fpart = n - (float)ipart;

	int	i = intToStr(ipart, res, 0);

	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_power(10, afterpoint);
		intToStr((int)fpart, res + i + 1, afterpoint);
	}
}

