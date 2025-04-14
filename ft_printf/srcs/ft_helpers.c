/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:31:55 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:39:33 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief store error status
 * @return error status
 */
int	*ft_write_error(void)
{
	static int	status = 0;

	return (&status);
}

/**
 * @brief set error status
 * @param status value to set error status
 */
void	ft_set_error(int status)
{
	int	*error;

	error = ft_write_error();
	*error = status;
}

/**
 * @brief check if value is format or bonus flag
 * @param c char to check
 * @param helper help to check format or flag
 * @return 1 if found and 0 if not
 */
int	ft_value_check(char c, int helper)
{
	char	*value;
	char	*bonus;

	value = "cspdiuxX%";
	bonus = "-0.# +";
	if (helper == 1)
	{
		while (*value != '\0')
		{
			if (*value == c)
				return (1);
			value++;
		}
	}
	else if (helper == 2)
	{
		while (*bonus != '\0')
		{
			if (*bonus == c)
				return (1);
			bonus++;
		}
	}
	return (0);
}

/**
 * @brief just putchar
 * @return len++
 */
int	ft_parsing_helper(const char str, int len)
{
	ft_putchar(str);
	len++;
	return (len);
}

/**
 * @brief count length of int
 * @n number
 * @return length of num
 */
int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
