/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:34:01 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:26:38 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief handle width format
 * @param p pointer to struct
 * @return how many chars have been printed
 */
int	ft_handle_width_size(t_int_print *p)
{
	int	t_size;
	int	add_size;

	t_size = p->numlen + p->has_sign + p->extra_space;
	if (p->c.zero && !p->c.dot && t_size < p->c.width)
	{
		add_size = p->c.width - t_size;
		while (add_size > 0)
		{
			ft_putchar('0');
			p->printed_chars++;
			add_size--;
		}
	}
	else
	{
		add_size = p->c.width - t_size;
		while (add_size > 0)
		{
			ft_putchar(' ');
			p->printed_chars++;
			add_size--;
		}
	}
	return (p->printed_chars);
}

/**
 * @brief handle precision
 * @param p print. Pointer to struct that contain num
 * @return how many chars have been printed
 */
int	ft_handle_precision_size(t_int_print *p)
{
	while (p->c.dotsize > ft_intlen(p->num))
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
int	ft_handle_zero_width_size(t_int_print *p)
{
	while (p->c.zerosize > ft_intlen(p->num) + p->has_sign + p->extra_space)
	{
		ft_putchar('0');
		p->printed_chars++;
		p->c.zerosize--;
	}
	return (p->printed_chars);
}

/**
 * @brief hanle '+','-' or space
 * @param p print. Pointer to struct that contain num
 * @return how many chars have been printed
 */
int	ft_handle_extra_sign(t_int_print *p)
{
	if (p->extra_space)
	{
		ft_putchar(' ');
		p->printed_chars++;
	}
	if (p->neg)
	{
		if (p->c.zero && !p->c.zerosize && !p->c.dot)
			return (p->printed_chars);
		else
			p->printed_chars = ft_just_minus(p);
	}
	else if (p->c.plus)
	{
		if (p->c.zero && !p->c.zerosize && !p->c.dot)
			return (p->printed_chars);
		else
		{
			ft_putchar('+');
			p->printed_chars++;
		}
	}
	return (p->printed_chars);
}

/**
 * @brief handle signs when zero is true
 * @param p print. Pointer to struct that contain num
 * @return how many chars have been printed
 */
int	ft_handle_zero_sign_space(t_int_print *p)
{
	if (p->c.zero && !p->c.zerosize && !p->c.dot)
	{
		if (p->neg)
		{
			ft_putchar('-');
			p->c.plus = 0;
			p->neg = 0;
			p->printed_chars++;
		}
		else if (p->c.plus || p->c.space)
		{
			if (p->c.plus)
				ft_putchar('+');
			if (p->c.space && !p->c.plus)
			{
				ft_putchar(' ');
				p->extra_space = 0;
				p->c.width--;
			}
			p->c.plus = 0;
			p->c.space = 0;
			p->printed_chars++;
		}
	}
	return (p->printed_chars);
}
