/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:03:52 by omizin            #+#    #+#             */
/*   Updated: 2025/03/13 16:32:40 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*next_value;

	next_value = (t_list *)malloc(sizeof(t_list));
	if (!next_value)
		return ((void *)0);
	next_value->content = content;
	next_value->next = (void *)0;
	return (next_value);
}
