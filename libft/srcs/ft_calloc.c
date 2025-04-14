/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:04:28 by omizin            #+#    #+#             */
/*   Updated: 2025/03/12 15:41:44 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t eltsize)
{
	void	*ptr;
	size_t	size;

	size = count * eltsize;
	if ((count > 0) && (size / count != eltsize))
		return ((void *)0);
	ptr = (void *)malloc(size);
	if (!ptr)
		return ((void *)0);
	ft_bzero(ptr, size);
	return (ptr);
}
