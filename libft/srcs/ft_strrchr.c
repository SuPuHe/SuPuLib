/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:11:08 by omizin            #+#    #+#             */
/*   Updated: 2025/03/14 13:46:17 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*found;

	found = (void *)0;
	while (*s)
	{
		if (*s == (char)c)
			found = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (found);
}
