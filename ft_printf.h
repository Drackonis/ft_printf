/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/29 15:23:31 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct			s_printf
{
	int					baseconv;
	char				strf[100];
	int					errorf;
	intmax_t			ipart;
	char				*str;
	int					strerror;
	double				m;
	long double			l;
	float				n;
	int					ret;
	va_list				arg;
	char				*format;
	int					i;
	int					diff;
	char				conv[30];
	char				base[17];
	int					c;
	int					d;
	signed char			d0;
	short				d1;
	long				d2;
	long long			d3;
	intmax_t			d4;
	unsigned int		d5;
	uintptr_t			d6;
	unsigned long		d7;
	unsigned long long	d8;
	int					is_flag;
	int					is_width;
	int					is_precision;
	int					f_precision;
	int					f_width;
	int					minus;
	int					plus;
	int					zero;
	int					space;
	int					prec_point;
	int					sharp;
	int					mput;
	int					pput;
	int					hcount;
	int					lcount;
	int					blcount;
	int					isneg;
	int					numlen;
	int					current_base;
}						t_printf;

t_printf				error_f(t_printf p);
t_printf				ft_flag_modifier(t_printf p);
t_printf				ft_putwidth(t_printf p, int len);
t_printf				ft_getconv(t_printf p, int base, int len);
void					ft_putnbr_intmax(intmax_t num);
int						ft_nbrlen(intmax_t n);
int						ft_ctoi(char c);
int						ft_nbr_conv(t_printf p, int start, int val);
t_printf				put_sharp(t_printf p);
t_printf				print_base_nbr(t_printf p);
t_printf				print_nbr(t_printf p);
t_printf				put_mp(t_printf p);
t_printf				put_nbr_modified(t_printf p);
t_printf				put_width3(t_printf p, int width);
t_printf				put_width2(t_printf p, int width);
t_printf				put_width(t_printf p);
t_printf				get_wipr(t_printf p);
t_printf				get_hll(t_printf p, char c);
t_printf				get_is_wipr(t_printf p);
t_printf				flag_modifier(t_printf p);
int						int_init_error(t_printf p);
t_printf				get_arg_h(t_printf p);
t_printf				get_arg_l(t_printf p);
t_printf				get_arg_base(t_printf p, int current_base);
t_printf				get_int_arg(t_printf p);
t_printf				get_arg(t_printf p);
t_printf				range_sharp(t_printf p);
t_printf				put_start_space(t_printf p);
t_printf				put_start_space2(t_printf p);
t_printf				get_start_flags(t_printf p, char c, int number);
t_printf				is_modifier(t_printf p);
t_printf				intialize2(t_printf p);
t_printf				initialize(t_printf p);
t_printf				get_conv(t_printf p);
int						check_error(t_printf p);
t_printf				init_call_conv(t_printf ptmp, t_printf p);
t_printf				do_conv(t_printf p, t_printf ptmp);
t_printf				call_conv(t_printf p, t_printf ptmp);
t_printf				check_conv(t_printf ptmp);
int						ft_printf(const char *format, ...);
void					reverse(char *str, int len);
intmax_t				ft_inttostr(intmax_t x, char *str, int d);
t_printf				ft_printf_blf(long double n
		, char *res, int afterpoint, t_printf p);
t_printf				ft_printf_lf(double n
		, char *res, int afterpoint, t_printf p);
t_printf				float_conv(t_printf p);
t_printf				char_conv(t_printf p);
t_printf				string_conv(t_printf p);
t_printf				string_null(t_printf p);
t_printf				ft_putstrpreci(t_printf p);
t_printf				str_bonus(t_printf p);
int						check_base(char *base);
t_printf				set_perc_conv(t_printf p);
int						ft_nbrlen_base(unsigned int nbr, int base);
int						ft_putunbr(unsigned long n, char *base);
int						ft_nbrulen_base(unsigned long nbr, int base);
t_printf				get_base_arg(t_printf p);
int						ft_putunbr_base(unsigned int nbr, char *base);
int						ft_putunbr_ll_base(unsigned long long nbrn, char *base);
int						check_is_conv(char c);
void					print_error(void);
int						cmp_flag(char c);
int						cmp_nb(char c);
int						cmp_lh(char c);
t_printf				call_conv_idx(t_printf p, int i);
void					printf_base_ll_nbr(t_printf p);
void					printf_base_hh_nbr(t_printf p);
void					ft_printf_base_select(t_printf p);
t_printf				ft_llmin(t_printf p);
int						ft_nbrhlen_base(intmax_t nbr, int base);
t_printf				put_zero(t_printf p);
int						ft_putunbr_hh_base(unsigned char nbr, char *base);
int						ft_putunbr_h_base(unsigned short nbr, char *base);
int						ft_unbrhhlen_base(unsigned short nbr, int base);
int						ft_unbrhlen_base(unsigned char nbr, int base);
t_printf				get_arg_uh(t_printf p);
int						along_format(t_printf p, int i);

#endif
