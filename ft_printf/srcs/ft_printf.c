/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:46:15 by omizin            #+#    #+#             */
/*   Updated: 2025/03/31 15:09:55 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Custom implementation of the printf function
 *
 * This function replicates the behavior of the standard printf, processing
 * format specifiers and variadic arguments to produce formatted output
 * It returns the total number of characters printed, or -1 if an error occurs
 *
 * @param str The format string containing text and format specifiers
 * @param ... Additional arguments corresponding to the format specifiers
 * @return total number of characters printed, or -1 if an error occurs
 */
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	ft_set_error(0);
	va_start(args, str);
	len = ft_parsing(str, args);
	va_end(args);
	if (*ft_write_error() == 1)
		return (-1);
	else
		return (len);
}
