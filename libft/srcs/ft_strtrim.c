/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:50:31 by omizin            #+#    #+#             */
/*   Updated: 2025/03/18 13:47:35 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*word;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return ((void *)0);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return ((void *)0);
	ft_strlcpy(word, (s1 + start), (end - start + 1));
	word[end - start] = '\0';
	return (word);
}
