/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:49:14 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:44:54 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr(long num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + 48);
	return (1);
}

/**
 * @brief print signs when minus flag exist
 * @return how many chars have been printed
 */
int	ft_print_int_with_minus2(t_int_print *p)
{
	if (p->neg)
	{
		ft_putchar('-');
		p->printed_chars++;
	}
	else if (p->c.plus)
	{
		ft_putchar('+');
		p->printed_chars++;
	}
	else if (p->extra_space)
	{
		ft_putchar(' ');
		p->printed_chars++;
	}
	return (p->printed_chars);
}

/**
 * @brief handle precision and width when minus flag exist
 * @return how many chars have been printed
 */
int	ft_print_int_with_minus(t_int_print *p)
{
	p->printed_chars = ft_print_int_with_minus2(p);
	while (p->c.dotsize > ft_intlen(p->num))
	{
		ft_putchar('0');
		p->printed_chars++;
		p->c.dotsize--;
	}
	if (p->numlen > 0)
	{
		ft_putnbr(p->num);
		p->printed_chars += ft_intlen(p->num);
	}
	while (p->c.width > p->printed_chars)
	{
		ft_putchar(' ');
		p->printed_chars++;
	}
	return (p->printed_chars);
}

/**
 * @brief print num with all flags
 * @param args the list of arguments provided to ft_printf
 * @return how many chars have been printed
 */
int	ft_print_int(int len, va_list args, t_bonus c)
{
	t_int_print	p;

	p.c = c;
	p.num = va_arg(args, int);
	p.printed_chars = 0;
	ft_prepare_number(&p);
	ft_prepare_format(&p);
	if (p.c.minus)
		p.printed_chars = ft_print_int_with_minus(&p);
	else
	{
		p.printed_chars = ft_handle_zero_sign_space(&p);
		p.printed_chars = ft_handle_width_size(&p);
		p.printed_chars = ft_handle_extra_sign(&p);
		p.printed_chars = ft_handle_precision_size(&p);
		p.printed_chars = ft_handle_zero_width_size(&p);
		p.printed_chars = ft_num_printing(&p);
	}
	return (len + p.printed_chars);
}
