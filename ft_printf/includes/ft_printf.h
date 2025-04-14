/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:09:08 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:03:04 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_bonus
{
	int	minus;
	int	zero;
	int	zerosize;
	int	dotsize;
	int	dot;
	int	sharp;
	int	space;
	int	plus;
	int	width;
	int	bonusflag;
}	t_bonus;

typedef struct s_int_print
{
	t_bonus	c;
	long	num;
	int		numlen;
	int		neg;
	int		printed_chars;
	int		has_sign;
	int		extra_space;
}	t_int_print;

//print functions
int		ft_printf(const char *str, ...);
int		ft_print(const char str, int len, va_list args, t_bonus c);
int		ft_print_char(int len, va_list args, t_bonus c);
int		ft_print_int(int len, va_list args, t_bonus c);
int		ft_print_uns(int len, va_list args, t_bonus c);
int		ft_print_ptr(int len, va_list args, t_bonus c);
int		ft_print_hex(int len, va_list args, t_bonus c, int helper);
int		ft_print_str_bonus(t_bonus c, char *str);

//helpers functions
int		ft_ptr_len(void *address);
int		ft_hex_len(unsigned int num);
int		ft_string_len(const char *s);
int		ft_intlen(long num);
int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putnbr(long num);
int		ft_putnbr_ptr(unsigned long num);
int		ft_putnbr_hex(unsigned int num, int helper);
int		*ft_write_error(void);
void	ft_set_error(int status);
int		ft_value_check(char c, int helper);
int		ft_parsing_helper(const char str, int len);
int		ft_parsing(const char *str, va_list args);

//handle functions
int		ft_handle_width_size(t_int_print *p);
int		ft_handle_precision_size(t_int_print *p);
int		ft_handle_zero_width_size(t_int_print *p);
int		ft_handle_extra_sign(t_int_print *p);
int		ft_handle_zero_sign_space(t_int_print *p);
void	ft_prepare_number(t_int_print *p);
void	ft_prepare_format(t_int_print *p);
int		ft_just_minus(t_int_print *p);
int		ft_num_printing(t_int_print *p);
int		ft_print_int_with_minus(t_int_print *p);
int		ft_print_int_with_minus2(t_int_print *p);
int		ft_hex_printing(t_int_print *p, int helper);
int		ft_handle_zero_hex(t_int_print *p, int helper);
int		ft_handle_precision_size_hex(t_int_print *p);
int		ft_handle_zero_width_size_hex(t_int_print *p);
int		ft_handle_sharp(t_int_print *p, int helper);

#endif
