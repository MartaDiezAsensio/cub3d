/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:34:45 by greus-ro          #+#    #+#             */
/*   Updated: 2024/10/03 17:36:03 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_get_next_line.h"

static char	*get_buffer(char *buffer)
{
	char	*buf;

	buf = buffer;
	if (buf == NULL)
	{
		buf = (char *)malloc(1);
		if (buf == NULL)
			return (NULL);
		*(buf) = '\0';
	}
	return (buf);
}

static void	*update_buffer(char *buffer, char *read_buffer, int num_bytes_read)
{
	char	*new_buffer;

	new_buffer = NULL;
	if (num_bytes_read > 0)
	{
		new_buffer = ft_strjoin(buffer, read_buffer);
		if (new_buffer == NULL)
			return (NULL);
		free(buffer);
	}
	if (num_bytes_read == 0)
		new_buffer = buffer;
	return (new_buffer);
}

static char	*get_line_from_buffer(char	**buffer, int num_bytes_read)
{
	char	*line;
	int		pos;
	char	*aux;
	size_t	len;

	line = NULL;
	len = ft_strlen(*buffer);
	pos = ft_istrchr(*buffer, "\n\r");
	if (pos >= 0)
	{
		line = ft_substr(*buffer, 0, pos + 1);
		aux = *buffer;
		*buffer = ft_substr(*buffer, pos + 1, len);
		free (aux);
		return (line);
	}
	if (num_bytes_read == 0)
	{
		line = ft_substr(*buffer, 0, len);
		*buffer = ft_ptr_free(*buffer);
	}
	return (line);
}

static char	*read_line(char **buffer, int fd)
{
	char	*read_buffer;
	char	*line;
	int		num_bytes;

	read_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (read_buffer == NULL)
		return (NULL);
	line = NULL;
	while (line == NULL)
	{
		num_bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (num_bytes < 0)
			return (ft_ptr_free(read_buffer));
		read_buffer[num_bytes] = '\0';
		*buffer = update_buffer(*buffer, read_buffer, num_bytes);
		if (*buffer == NULL)
			return (ft_ptr_free(read_buffer));
		line = get_line_from_buffer(buffer, num_bytes);
	}
	free(read_buffer);
	return (line);
}

char	*ft_get_next_line(int fd)
{
	static char			*buffer;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_buffer(buffer);
	if (buffer == NULL)
		return (NULL);
	line = read_line(&buffer, fd);
	if (line == NULL)
		buffer = ft_ptr_free(buffer);
	if (line != NULL && ft_strlen(line) == 0)
		line = ft_ptr_free(line);
	return (line);
}
