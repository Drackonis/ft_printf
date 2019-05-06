#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h" //includes abusifs

typedef struct		s_printf
{
	int		ret;
	va_list		arg;
	char		*format;
	int		i;
	int		diff;
	char		conv[30];
	int		c;
	int		d;
	signed char	d0;
	short		d1;	
	long		d2;
	long long 	d3;
	intmax_t	d4;
	int		is_flag;
	int		is_width;
	int		is_precision;
	int		f_precision;
	int		f_width;
	//int		is_noread;
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int 		mput;
	int		hcount;
	int		lcount;
	int		isneg;
	int		numlen;

}			t_printf;

int			ft_printf(const char *format, ...);
int			ft_putnbr_base(int, char*);
t_printf		is_modifier(t_printf p);

#endif
