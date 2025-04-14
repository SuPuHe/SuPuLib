/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:09:09 by omizin            #+#    #+#             */
/*   Updated: 2025/03/12 15:42:10 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *a1, const void *a2, size_t size)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	if (size == 0)
		return (0);
	s1 = (const unsigned char *)a1;
	s2 = (const unsigned char *)a2;
	i = 0;
	while ((i < size - 1) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
