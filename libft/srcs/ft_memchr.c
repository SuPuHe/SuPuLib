/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:00:38 by omizin            #+#    #+#             */
/*   Updated: 2025/03/12 15:42:07 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *block, int c, size_t size)
{
	unsigned char	*ptr;
	unsigned char	value;

	ptr = (unsigned char *)block;
	value = (unsigned char)c;
	while (size--)
	{
		if (*ptr == value)
			return (ptr);
		ptr++;
	}
	return ((void *)0);
}
