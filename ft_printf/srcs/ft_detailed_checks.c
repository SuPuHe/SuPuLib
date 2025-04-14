/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detailed_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:37:03 by omizin            #+#    #+#             */
/*   Updated: 2025/04/02 11:08:18 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief this function check presicion
 */
static void	ft_detailed_check_4(const char *str, t_bonus *c, int *i)
{
	if (str[*i] == '.' && (str[*i + 1] >= '0' && (str[*i + 1]) <= '9'))
	{
		if (c->dot > 0)
			c->dotsize = 0;
		c->dot++;
		(*i)++;
		while (str[*i] >= '0' && (str[*i]) <= '9')
		{
			c->dotsize = (c->dotsize * 10) + (str[*i] - 48);
			(*i)++;
		}
	}
	else if (str[*i] == '.' && !(str[*i + 1] >= '0' && (str[*i + 1]) <= '9'))
		c->dot++;
}

/**
 * @brief this function check zerosize
 */
static void	ft_detailed_check_3(const char *str, t_bonus *c, int *i)
{
	if (str[*i] == '0' && (str[*i + 1] >= '0' && (str[*i + 1]) <= '9'))
	{
		c->zero++;
		(*i)++;
		while (str[*i] >= '0' && (str[*i]) <= '9')
		{
			c->zerosize = (c->zerosize * 10) + (str[*i] - 48);
			(*i)++;
		}
	}
	else if (str[*i] == '0' && !(str[*i + 1] >= '0' && (str[*i + 1]) <= '9'))
		c->zero++;
}

/**
 * @brief this function check for bonus flags
 * @param i string counter
 */
static void	ft_detailed_check_2(const char *str, t_bonus *c, int *i)
{
	if (str[*i] == '-')
		c->minus++;
	else if (str[*i] == '0')
		ft_detailed_check_3(str, c, i);
	if (ft_value_check(str[*i], 1))
		return ;
	else if (str[*i] == '#')
		c->sharp++;
	else if (str[*i] == ' ')
		c->space++;
	else if (str[*i] == '+')
		c->plus++;
	if (str[*i] == '.')
		ft_detailed_check_4(str, c, i);
}

/**
 * @brief this function check for width
 * @param c count. Pointer to structure that count bonusflags
 */
static int	ft_detailed_check(const char *str, t_bonus *c)
{
	int	i;

	i = 0;
	while (!(ft_value_check(str[i], 1)))
	{
		if (ft_value_check(str[i], 2))
			c->bonusflag = 1;
		ft_detailed_check_2(str, c, &i);
		if (ft_value_check(str[i], 1))
			return (i);
		if (str[i] >= '1' && str[i] <= '9')
		{
			c->width = str[i] - 48;
			i++;
			while (str[i] >= '0' && str[i] <= '9')
			{
				c->width = (c->width * 10) + (str[i] - 48);
				i++;
			}
		}
		else
			i++;
	}
	return (i);
}

/**
 * @brief parsing string
 * @param str just a string
 * @param args variadic arguments list
 * @return how many chars have been printed
 */
int	ft_parsing(const char *str, va_list args)
{
	int		i;
	int		len;
	int		detailed_check_len;
	t_bonus	c;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			len = ft_parsing_helper(str[i], len);
		else if (str[i] == '%')
		{
			c = (t_bonus){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			detailed_check_len = ft_detailed_check(&str[i + 1], &c);
			len = ft_print(str[i + 1 + detailed_check_len], len, args, c);
			i += detailed_check_len + 1;
		}
		i++;
	}
	return (len);
}
