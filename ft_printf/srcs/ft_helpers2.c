/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:52:56 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:21:42 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_string_len(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0' && *ft_write_error() == 0)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_ptr(unsigned long num)
{
	char	*hex_low;
	char	hex[16];
	int		i;
	int		c;

	hex_low = "0123456789abcdef";
	i = 0;
	if (num == 0)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	while (num != 0)
	{
		hex[i++] = hex_low[num % 16];
		num = num / 16;
	}
	c = i;
	while (--i >= 0)
		ft_putchar(hex[i]);
	return (c + 2);
}

int	ft_ptr_len(void *address)
{
	int				len;
	unsigned long	num;

	len = 2;
	num = (unsigned long)address;
	if (num == 0)
		return (3);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 1;
	while (num >= 16)
	{
		num /= 16;
		len++;
	}
	return (len);
}
