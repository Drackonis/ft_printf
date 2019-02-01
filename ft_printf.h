#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);

typedef struct s_printf
{
	va_list	arg;
	char *format;
	int	i;


}		t_printf;

#endif
