/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:24:50 by omizin            #+#    #+#             */
/*   Updated: 2025/03/14 11:49:25 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*word;
	size_t	i;
	size_t	string_len;

	if (!s)
		return ((void *)0);
	string_len = ft_strlen(s);
	if (start >= string_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > string_len - start)
		len = string_len - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
