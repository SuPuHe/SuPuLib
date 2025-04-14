/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:24:15 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:48:21 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief print str with all flags
 * @param args the list of arguments provided to ft_printf
 * @return how many chars have been printed
 */
static int	ft_print_str(int len, va_list args, t_bonus c)
{
	char	*str;
	int		i;

	str = va_arg(args, char *);
	i = ft_print_str_bonus(c, str);
	return (len + i);
}

/**
 * @brief handle width and zerosize
 * @return how many chars have been printed
 */
static int	ft_handle_procent(t_bonus c, int bonus_len)
{
	if (c.zerosize > 1 && c.minus)
	{
		c.width = c.zerosize;
		c.zerosize = 0;
	}
	while (c.width > 1)
	{
		ft_putchar(' ');
		c.width--;
		bonus_len++;
	}
	while (c.zerosize > 1)
	{
		ft_putchar('0');
		c.zerosize--;
		bonus_len++;
	}
	return (bonus_len);
}

/**
 * @brief print procent with bonus flags
 * @return how many chars have been printed
 */
static int	ft_put_procent_bonus(t_bonus c)
{
	int	bonus_len;

	bonus_len = 0;
	if (c.width > 1 || c.zerosize > 1)
	{
		if (c.minus > 0)
		{
			ft_putchar('%');
			bonus_len++;
		}
		bonus_len = ft_handle_procent(c, bonus_len);
		if (c.minus == 0)
		{
			ft_putchar('%');
			bonus_len++;
		}
	}
	return (bonus_len);
}

/**
 * @brief print procent with bonus flags
 * @return how many chars have been printed
 */
static int	ft_print_procent(int len, t_bonus c)
{
	if (c.width <= 1 && c.zerosize <= 1)
	{
		ft_putchar('%');
		len++;
		return (len);
	}
	len += ft_put_procent_bonus(c);
	return (len);
}

/**
 * @brief check for format and call another ft
 * @return how many chars have been printed
 */
int	ft_print(const char str, int len, va_list args, t_bonus c)
{
	if (str == 'c')
		len = ft_print_char(len, args, c);
	if (str == 's')
		len = ft_print_str(len, args, c);
	if (str == 'p')
		len = ft_print_ptr(len, args, c);
	if (str == 'd' || str == 'i')
		len = ft_print_int(len, args, c);
	if (str == 'u')
		len = ft_print_uns(len, args, c);
	if (str == 'x')
		len = ft_print_hex(len, args, c, 1);
	if (str == 'X')
		len = ft_print_hex(len, args, c, 2);
	if (str == '%')
		len = ft_print_procent(len, c);
	return (len);
}
