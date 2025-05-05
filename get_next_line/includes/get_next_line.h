/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:33:00 by omizin            #+#    #+#             */
/*   Updated: 2025/05/05 21:57:13 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	ssize_t	bytes;
	ssize_t	i;
	char	*buf;
}	t_gnl;

t_gnl	**get_gnl_array(void);
char	*get_next_line(int fd);
char	*ft_free_and_return_null(char *line, t_gnl **gnl_ptr);
char	*ft_error_check(char *line, t_gnl **gnl_ptr);

#endif
