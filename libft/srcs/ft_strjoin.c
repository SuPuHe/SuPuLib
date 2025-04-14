/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:24:31 by omizin            #+#    #+#             */
/*   Updated: 2025/03/13 16:54:23 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*word;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return ((void *)0);
	ft_memcpy(word, s1, ft_strlen(s1));
	ft_memcpy(word + ft_strlen(s1), s2, ft_strlen(s2));
	word[len] = '\0';
	return (word);
}
