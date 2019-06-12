#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h" //includes abusifs

typedef struct		s_printf
{
	int				baseconv;
	/* -3 = char %c
	 * -2 = %%
	 * -1 = float %f
	 * 0 = decimal %d %i
	 * 1 = unsigned decimal %u
	 * 2 = octal %o
	 * 3 = exadecimal %x
	 * 4 = maj exadecimal %X
	 * 5 = adress %p
	*/
	char			strf[100]; // float
	int				errorf; //float
	char			*str; //stringconv
	double			m; //floatconv
	long double		l;
	float			n;
	int				ret;
	va_list			arg;
	char			*format;
	int				i;
	int				diff;
	char			conv[30];
	char			base[17];
	int				c;
	int				d;
	signed char		d0;
	short			d1;	
	long			d2;
	long long		d3;
	intmax_t		d4;
	unsigned int	d5;
	uintptr_t		d6;
	int				is_flag;
	int				is_width;
	int				is_precision;
	int				f_precision;
	int				f_width;
	//int			is_noread;
	int				minus;
	int				plus;
	int				zero;
	int				space;
	int				prec_point;
	int				sharp;
	int				mput;
	int				pput;
	int				hcount;
	int				lcount;
	int				Lcount;
	int				isneg;
	int				numlen;
}					t_printf;

t_printf		error_f(t_printf p);
t_printf		ft_flag_modifier(t_printf p);
t_printf		ft_putwidth(t_printf p, int len);
t_printf		ft_getconv(t_printf p, int base, int len);
void			ft_putnbr_intmax(intmax_t num);
int				ft_nbrlen(intmax_t n);
int				ft_ctoi(char c);
int				ft_nbr_conv(t_printf p, int start, int val);
t_printf		put_sharp(t_printf p);
t_printf		print_base_nbr(t_printf p);
t_printf		print_nbr(t_printf p);
t_printf		put_mp(t_printf p);
t_printf		put_nbr_modified(t_printf p);
t_printf		put_width2(t_printf p, int width);
t_printf		put_width(t_printf p);
t_printf		get_wipr(t_printf p);
t_printf		get_hll(t_printf p, char c);
t_printf		get_is_wipr(t_printf p);
t_printf		flag_modifier(t_printf p);
int				int_init_error(t_printf p);
t_printf		get_arg_h(t_printf p);
t_printf		get_arg_l(t_printf p);
t_printf		get_arg_base(t_printf p, int current_base);
t_printf		get_int_arg(t_printf p);
t_printf		get_arg(t_printf p);
t_printf		range_sharp(t_printf p);
t_printf		put_start_space(t_printf p);
t_printf		get_start_flags(t_printf p, char c, int number);
t_printf		is_modifier(t_printf p);
t_printf		intialize2(t_printf p);
t_printf		initialize(t_printf p);
t_printf		get_conv(t_printf p);
t_printf		locat_conv(t_printf p);
t_printf		put_percent(t_printf p);
t_printf		octo_conv(t_printf p);
t_printf		dec_conv(t_printf p);
t_printf		exa_conv(t_printf p);
t_printf		mexa_conv(t_printf p);
t_printf		int_conv(t_printf p);
int				check_error(t_printf p);
t_printf		init_call_conv(t_printf ptmp, t_printf p);
t_printf		do_conv(t_printf p, t_printf ptmp);
t_printf		call_conv(t_printf p, t_printf ptmp);
t_printf		check_conv(t_printf ptmp);
int				ft_printf(const char *format, ...);
void			reverse(char *str, int len);
int				ft_inttostr(int x, char *str, int d);
void			ft_printf_f(float n, char *res, int afterpoint);
void			ft_printf_blf(long double n, char *res, int afterpoint);
void			ft_printf_lf(double n, char *res, int afterpoint);
t_printf		float_conv(t_printf p);
t_printf		char_conv(t_printf p);
t_printf		string_conv(t_printf p);
t_printf		ft_putstrpreci(t_printf p);
t_printf		str_bonus(t_printf p);
int				check_base(char *base);
int				ft_nbrlen_base(unsigned int nbr, int base);
int				ft_putnbr_base(int nbr, char *base);

#endif
