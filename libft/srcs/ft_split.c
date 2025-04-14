/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:37 by omizin            #+#    #+#             */
/*   Updated: 2025/03/17 14:35:35 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static char	*ft_word_sep(const char *start, const char *end)
{
	char	*temp;
	char	*word;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return ((void *)0);
	temp = word;
	while (start < end)
	{
		*temp = *start;
		temp++;
		start++;
	}
	*temp = '\0';
	return (word);
}

static void	ft_arr_free(char **words, int i)
{
	while (i > 0)
		free(words[--i]);
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char		**words;
	const char	*start;
	int			i;

	words = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!words)
		return ((void *)0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s != c && *s)
				s++;
			words[i] = ft_word_sep(start, s);
			if (!words[i])
				return (ft_arr_free(words, i), (void *)0);
			i++;
		}
		else
			s++;
	}
	words[i] = (void *)0;
	return (words);
}
