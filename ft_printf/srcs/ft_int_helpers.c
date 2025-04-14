/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:37:44 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:29:36 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief prepare num to formatting
 * @param p print. Poiner to struct that contain num
 */
void	ft_prepare_number(t_int_print *p)
{
	p->numlen = ft_intlen(p->num);
	p->neg = 0;
	if (p->num < 0)
	{
		p->neg = 1;
		p->num = -p->num;
	}
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
 * @brief prepare for some edge cases
 * @param p print. Poiner to struct that contain num
 */
void	ft_prepare_format(t_int_print *p)
{
	p->has_sign = 0;
	p->extra_space = 0;
	if (p->neg || p->c.plus)
		p->has_sign = 1;
	if (p->c.space && !p->c.plus && !p->neg)
		p->extra_space = 1;
}

int	ft_just_minus(t_int_print *p)
{
	ft_putchar('-');
	p->printed_chars++;
	return (p->printed_chars);
}

int	ft_num_printing(t_int_print *p)
{
	if (p->numlen > 0)
	{
		ft_putnbr(p->num);
		p->printed_chars += ft_intlen(p->num);
	}
	return (p->printed_chars);
}
