/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:16:35 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:14:57 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief print number in hex base
 * @param p print. Pointer to struct that contain num
 * @param helper help to print in lowercase or uppercase
 * @return how many chars have been printed
 */
int	ft_hex_printing(t_int_print *p, int helper)
{
	if (p->numlen > 0)
	{
		ft_putnbr_hex(p->num, helper);
		p->printed_chars += ft_hex_len(p->num);
	}
	return (p->printed_chars);
}

/**
 * @brief handle zero size when sharp is true
 * @param p print. Pointer to struct that contain num
 * @param helper help to print in lowercase or uppercase
 * @return how many chars have been printed
 */
int	ft_handle_zero_hex(t_int_print *p, int helper)
{
	if (p->c.zero && !p->c.zerosize && !p->c.dot)
	{
		if (p->c.sharp && p->num != 0)
		{
			if (helper == 1)
				ft_putstr("0x");
			else if (helper == 2)
				ft_putstr("0X");
			p->printed_chars += 2;
		}
	}
	return (p->printed_chars);
}

/**
 * @brief handle precision
 * @param p print. Pointer to struct that contain num
 * @return how many chars have been printed
 */
int	ft_handle_precision_size_hex(t_int_print *p)
{
	while (p->c.dotsize > ft_hex_len(p->num))
	{
		ft_putchar('0');
		p->printed_chars++;
		p->c.dotsize--;
	}
	return (p->printed_chars);
}

/**
 * @brief handle zerosize
 * @param p print. Pointer to struct that contain num
 * @return how many chars have been printed
 */
int	ft_handle_zero_width_size_hex(t_int_print *p)
{
	while (p->c.zerosize > ft_hex_len(p->num) + p->has_sign)
	{
		ft_putchar('0');
		p->printed_chars++;
		p->c.zerosize--;
	}
	return (p->printed_chars);
}

/**
 * @brief handle sharp flag
 * @param p print. Pointer to struct that contain num
 * @param helper help to print in lowercase or uppercase
 * @return how many chars have been printed
 */
int	ft_handle_sharp(t_int_print *p, int helper)
{
	if (p->c.sharp && p->num != 0)
	{
		if (p->c.zero && !p->c.zerosize && !p->c.dot)
			return (p->printed_chars);
		if (helper == 1)
			ft_putstr("0x");
		else if (helper == 2)
			ft_putstr("0X");
		p->printed_chars += 2;
	}
	return (p->printed_chars);
}
