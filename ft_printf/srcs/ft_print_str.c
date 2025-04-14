/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:35:41 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:53:03 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief print str when minis is false
 * @return how many chars have been printed
 */
static int	ft_print_str_without2(t_bonus c, int b_len, char *str, int strlen)
{
	while (c.width != strlen)
	{
		ft_putchar(' ');
		c.width--;
		b_len++;
	}
	b_len += ft_putstr(str);
	return (b_len);
}

/**
 * @brief handle precision when minis is false
 * @return how many chars have been printed
 */
static int	ft_print_str_without(t_bonus c, int b_len, char *str, int strlen)
{
	int	printlen;

	if (c.dot > 0)
	{
		if (c.dotsize < strlen)
			printlen = c.dotsize;
		else
			printlen = strlen;
		c.width -= printlen;
		while (c.width > 0)
		{
			ft_putchar(' ');
			c.width--;
			b_len++;
		}
		while (printlen > 0)
		{
			ft_putchar(*str++);
			printlen--;
			b_len++;
		}
	}
	else if (c.dot == 0)
		b_len = ft_print_str_without2(c, b_len, str, strlen);
	return (b_len);
}

/**
 * @brief print str when minus is true
 * @return how many chars have been printed
 */
static int	ft_print_str_with2(t_bonus c, int b_len, char *str, int strlen)
{
	b_len += ft_putstr(str);
	while (c.width != strlen)
	{
		ft_putchar(' ');
		c.width--;
		b_len++;
	}
	return (b_len);
}

/**
 * @brief handle precision when minus is true
 * @return how many chars have been printed
 */
static int	ft_print_str_with(t_bonus c, int b_len, char *str, int strlen)
{
	int	printlen;

	if (c.dot > 0)
	{
		if (c.dotsize < strlen)
			printlen = c.dotsize;
		else
			printlen = strlen;
		c.width -= printlen;
		while (printlen > 0)
		{
			ft_putchar(*str++);
			printlen--;
			b_len++;
		}
		while (c.width > 0)
		{
			ft_putchar(' ');
			c.width--;
			b_len++;
		}
	}
	else if (c.dot == 0)
		b_len = ft_print_str_with2(c, b_len, str, strlen);
	return (b_len);
}

/**
 * @brief print str with all flags
 * @param args the list of arguments provided to ft_printf
 * @return how many chars have been printed
 */
int	ft_print_str_bonus(t_bonus c, char *str)
{
	int	b_len;
	int	strlen;

	b_len = 0;
	if (!str)
	{
		str = "(null)";
		strlen = ft_string_len(str);
	}
	else
		strlen = ft_string_len(str);
	if (c.dot == 0 && c.width <= strlen)
	{
		b_len = ft_putstr(str);
		return (b_len);
	}
	if (c.minus == 0)
		b_len = ft_print_str_without(c, b_len, str, strlen);
	if (c.minus > 0)
		b_len = ft_print_str_with(c, b_len, str, strlen);
	return (b_len);
}
