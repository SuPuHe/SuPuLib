/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:21:36 by omizin            #+#    #+#             */
/*   Updated: 2025/03/13 10:38:43 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t size)
{
	const unsigned char	*src;
	unsigned char		*dest;

	if (!to && !from)
		return ((void *)0);
	src = (const unsigned char *)from;
	dest = (unsigned char *)to;
	while (size--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (to);
}
