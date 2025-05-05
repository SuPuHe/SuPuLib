/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:28:46 by omizin            #+#    #+#             */
/*   Updated: 2025/05/05 22:01:36 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	**get_gnl_array(void)
{
	static t_gnl	*gnl_array[1024];

	return (gnl_array);
}

char	*ft_free_and_return_null(char *line, t_gnl **gnl_ptr)
{
	t_gnl	*gnl;

	gnl = *gnl_ptr;
	free(line);
	if (gnl)
	{
		if (gnl->buf)
		{
			free(gnl->buf);
			gnl->buf = NULL;
		}
		free(gnl);
		*gnl_ptr = NULL;
	}
	return (NULL);
}

char	*ft_error_check(char *line, t_gnl **gnl_ptr)
{
	t_gnl	*gnl;

	gnl = *gnl_ptr;
	if (gnl->bytes == -1)
		return (ft_free_and_return_null(line, gnl_ptr));
	if (line)
	{
		if (gnl->buf)
		{
			free(gnl->buf);
			gnl->buf = NULL;
		}
		return (line);
	}
	return (ft_free_and_return_null(line, gnl_ptr));
}
