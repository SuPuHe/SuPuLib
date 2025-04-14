/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:41:38 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:41:52 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief write char.
 * This function checks for an existing error status before attempting to write.
 * If the write operation fails, it sets an error status.
 * @param c char to write
 * @return number of bytes written
 */
int	ft_putchar(char c)
{
	int	status;
	int	*error;

	status = 0;
	error = ft_write_error();
	if (*error != 1)
	{
		status = write(1, &c, 1);
		if (status == -1)
			ft_set_error(1);
	}
	return (status);
}

/**
 * @brief just write char
 * @return bonuslen++ or bonuslen if width > 1
 */
static int	ft_putchar_bonus_2(char letter, t_bonus c, int bonus_len)
{
	if (c.width <= 1)
	{
		ft_putchar(letter);
		bonus_len++;
		return (bonus_len);
	}
	return (bonus_len);
}

/**
 * @brief handle bonus flags
 * @param letter letter to write
 * @return how namy chars have been printed
 */
static int	ft_putchar_bonus(char letter, t_bonus c)
{
	int	bonus_len;

	bonus_len = 0;
	bonus_len = ft_putchar_bonus_2(letter, c, bonus_len);
	if (c.width > 1)
	{
		if (c.minus > 0)
		{
			ft_putchar(letter);
			bonus_len++;
		}
		while (c.width > 1)
		{
			ft_putchar(' ');
			c.width--;
			bonus_len++;
		}
		if (c.minus == 0)
		{
			ft_putchar(letter);
			bonus_len++;
		}
	}
	return (bonus_len);
}

/**
 * @brief Prints a character with optional formatting
 * and updates the total length
 * @param len The current length of the printed output
 * @param args The variadic arguments list containing the character to print
 * @param c The formatting options
 * @return how many chars have been printed
 */
int	ft_print_char(int len, va_list args, t_bonus c)
{
	char	letter;

	letter = va_arg(args, int);
	len += ft_putchar_bonus(letter, c);
	return (len);
}
