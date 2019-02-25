#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_printf
{
	va_list	arg;
	char	*format;
	int	i;
	int	diff;
	char	conv[30];
	int	c;
	int	d;
	int	is_flag;
	int	is_width;
	int	is_precision;
	int	minus;
	int	plus;
	int	zero;

}		t_printf;

t_printf	ft_printf(const char *format, ...);
void		ft_putnbr_base(int, char*);

#endif
