/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:34:12 by omizin            #+#    #+#             */
/*   Updated: 2025/03/13 12:47:46 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_string;
	size_t	len;

	if (!s || !f)
		return ((void *)0);
	len = ft_strlen(s);
	new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_string)
		return ((void *)0);
	len = 0;
	while (s[len] != '\0')
	{
		new_string[len] = f(len, s[len]);
		len++;
	}
	new_string[len] = '\0';
	return (new_string);
}
