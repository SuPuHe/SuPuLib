/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:35:26 by omizin            #+#    #+#             */
/*   Updated: 2025/03/12 15:42:16 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t size)
{
	unsigned char		*dest;
	const unsigned char	*src;

	if (to == from || size == 0)
		return (to);
	dest = (unsigned char *)to;
	src = (const unsigned char *)from;
	if (dest > src && dest < src + size)
	{
		dest += size;
		src += size;
		while (size--)
		{
			dest--;
			src--;
			*dest = *src;
		}
	}
	else
	{
		while (size--)
			*dest++ = *src++;
	}
	return (to);
}
