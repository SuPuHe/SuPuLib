/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:38:20 by omizin            #+#    #+#             */
/*   Updated: 2025/03/12 15:42:21 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *block, int c, size_t size)
{
	unsigned char	*ptr;
	unsigned char	value;

	ptr = (unsigned char *)block;
	value = (unsigned char)c;
	while (size--)
	{
		*ptr = value;
		ptr++;
	}
	return (block);
}
