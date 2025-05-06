/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:27:58 by omizin            #+#    #+#             */
/*   Updated: 2025/05/06 10:36:43 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/**
 * @brief This function copy the line and add new char with null terminator
 * @param line The line to copy.
 * @param c The char to add.
 * @return A new string with the new char added or NULL in case of an error.
*/
char	*ft_append(char *line, char c, ssize_t len)
{
	char	*temp;
	ssize_t	j;

	temp = (char *)malloc(sizeof(char) * (len + 2));
	if (!temp)
		return (free(line), NULL);
	j = 0;
	while (j < len)
	{
		temp[j] = line[j];
		j++;
	}
	temp[len] = c;
	temp[len + 1] = '\0';
	free(line);
	return (temp);
}

/**
 * @brief Reads a line from a file descriptor until a newline or EOF.
 * @param gnl_ptr Pointer to a structure.
 * @return A dynamically allocated string or NULL in case of an error or EOF.
 */
char	*ft_read_line(int fd, t_gnl **gnl_ptr)
{
	char	*line;
	ssize_t	len;
	int		read_more;
	t_gnl	*gnl;

	line = NULL;
	len = 0;
	read_more = 1;
	gnl = *gnl_ptr;
	while (read_more)
	{
		if (gnl->i >= gnl->bytes)
		{
			gnl->bytes = read(fd, gnl->buf, BUFFER_SIZE);
			if (gnl->bytes <= 0)
				return (ft_error_check(line, gnl_ptr));
			gnl->i = 0;
		}
		if (gnl->buf[gnl->i] == '\n')
			read_more = 0;
		line = ft_append(line, gnl->buf[gnl->i++], len++);
		if (!line)
			return (ft_free_and_return_null(line, gnl_ptr));
	}
	return (line);
}

/**
 * @brief Reads the next line
 * @param fd The file descriptor to read from.
 * @return A dynamically allocated string or NULL in case of an error.
 */
char	*get_next_line(int fd)
{
	t_gnl	**gnl_array;

	gnl_array = get_gnl_array();
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!gnl_array[fd])
	{
		gnl_array[fd] = (t_gnl *)malloc(sizeof(t_gnl));
		if (!gnl_array[fd])
			return (NULL);
		gnl_array[fd]->buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (!gnl_array[fd]->buf)
		{
			free(gnl_array[fd]);
			gnl_array[fd] = NULL;
			return (NULL);
		}
		gnl_array[fd]->i = 0;
		gnl_array[fd]->bytes = 0;
	}
	return (ft_read_line(fd, &gnl_array[fd]));
}
