/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:10:09 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:42:16 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_hex(unsigned int num, int helper)
{
	char	*hex_low;
	char	*hex_upp;
	int		len;

	hex_upp = "0123456789ABCDEF";
	hex_low = "0123456789abcdef";
	len = 0;
	if (num >= 16)
	{
		len += ft_putnbr_hex(num / 16, helper);
	}
	if (helper == 1)
		ft_putchar(hex_low[num % 16]);
	else if (helper == 2)
		ft_putchar(hex_upp[num % 16]);
	len++;
	return (len);
}

/**
 * @brief prepare num to formatting and prepare for some edge cases
 * @param p print. Poiner to struct that contain num
 */
static void	ft_prepare_hex(t_int_print *p)
{
	p->has_sign = 0;
	p->extra_space = 0;
	if (p->c.sharp && p->num != 0)
		p->has_sign = 2;
	p->numlen = ft_hex_len(p->num);
	p->neg = 0;
	if (p->c.dot && p->c.dotsize > p->numlen)
		p->numlen = p->c.dotsize;
	if (p->c.dot && p->c.zerosize >= p->c.width)
	{
		p->c.width = p->c.zerosize;
		p->c.zerosize = 0;
	}
	if (p->num == 0 && p->c.dot == 1 && p->c.dotsize == 0)
		p->numlen = 0;
}

/**
 * @brief print #flag when num !=0 and minus flag is exist
 * @return how many chars have been printed
 */
static int	ft_print_hex_with_minus2(t_int_print *p, int helper)
{
	if (p->c.sharp && p->num != 0)
	{
		if (helper == 1)
			ft_putstr("0x");
		else if (helper == 2)
			ft_putstr("0X");
		p->printed_chars += 2;
	}
	return (p->printed_chars);
}

/**
 * @brief print pressicion flag and width when minus flag is exist
 * @return how many chars have been printed
 */
static int	ft_print_hex_with_minus(t_int_print *p, int helper)
{
	p->printed_chars = ft_print_hex_with_minus2(p, helper);
	while (p->c.dotsize > ft_hex_len(p->num))
	{
		ft_putchar('0');
		p->printed_chars++;
		p->c.dotsize--;
	}
	if (p->numlen > 0)
	{
		ft_putnbr_hex(p->num, helper);
		p->printed_chars += ft_hex_len(p->num);
	}
	while (p->c.width > p->printed_chars)
	{
		ft_putchar(' ');
		p->printed_chars++;
	}
	return (p->printed_chars);
}

/**
 * @brief print num im hex base with all flags
 * @param args the list of arguments provided to ft_printf
 * @return how many chars have been printed
 */
int	ft_print_hex(int len, va_list args, t_bonus c, int helper)
{
	t_int_print	p;

	p.c = c;
	p.num = va_arg(args, unsigned int);
	p.printed_chars = 0;
	ft_prepare_hex(&p);
	if (p.c.minus)
		p.printed_chars = ft_print_hex_with_minus(&p, helper);
	else
	{
		p.printed_chars = ft_handle_zero_hex(&p, helper);
		p.printed_chars = ft_handle_width_size(&p);
		p.printed_chars = ft_handle_sharp(&p, helper);
		p.printed_chars = ft_handle_precision_size_hex(&p);
		p.printed_chars = ft_handle_zero_width_size_hex(&p);
		p.printed_chars = ft_hex_printing(&p, helper);
	}
	return (len + p.printed_chars);
}
