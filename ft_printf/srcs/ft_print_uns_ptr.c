/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:52:30 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:54:27 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief print unsigned num with all flags
 * @param args the list of arguments provided to ft_printf
 * @return how many chars have been printed
 */
int	ft_print_uns(int len, va_list args, t_bonus c)
{
	t_int_print		p;
	unsigned int	num;

	p.c = c;
	num = va_arg(args, unsigned int);
	p.num = num;
	p.printed_chars = 0;
	ft_prepare_number(&p);
	ft_prepare_format(&p);
	if (p.c.minus)
		p.printed_chars = ft_print_int_with_minus(&p);
	else
	{
		p.printed_chars = ft_handle_width_size(&p);
		p.printed_chars = ft_handle_precision_size(&p);
		p.printed_chars = ft_handle_zero_width_size(&p);
		p.printed_chars = ft_num_printing(&p);
	}
	return (len + p.printed_chars);
}

/**
 * @brief handle ptr with all bonus flags
 * @return how many chars have been printed
 */
int	ft_print_ptr_bonus(t_bonus c, unsigned long address, int strlen)
{
	int	bonuslen;

	bonuslen = 0;
	if (c.width <= strlen)
	{
		bonuslen = ft_putnbr_ptr(address);
		return (bonuslen);
	}
	if (c.minus > 0)
		bonuslen += ft_putnbr_ptr(address);
	if (c.width > strlen)
	{
		while (c.width != strlen)
		{
			ft_putchar(' ');
			c.width--;
			bonuslen++;
		}
	}
	if (c.minus == 0)
		bonuslen += ft_putnbr_ptr(address);
	return (bonuslen);
}

/**
 * @brief print ptr with all flags
 * @param args the list of arguments provided to ft_printf
 * @return how many chars have been printed
 */
int	ft_print_ptr(int len, va_list args, t_bonus c)
{
	void	*address;
	int		ptrlen;

	address = va_arg(args, void *);
	ptrlen = ft_ptr_len(address);
	len += ft_print_ptr_bonus(c, (unsigned long)address, ptrlen);
	return (len);
}
