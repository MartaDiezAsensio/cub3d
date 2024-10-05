/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:41:11 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/05 23:43:14 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_get_next_line.h"
#include "map.h"
#include "libft.h"

bool	config_line_is_map(const char *line)
{
	if (map_cell_is_valid(line[0]))
		return (true);
	return (false);
}

bool	config_line_is_color(const char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (true);
	return (false);
}

bool	config_line_is_texture(const char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}

bool	config_line_is_valid(const char *line)
{
	if (config_line_is_map(line) || config_line_is_texture(line) || \
			config_line_is_color(line))
		return (true);
	return (false);
}

bool	config_line_get_trimmed(char **trim_line, int fd)
{
	char	*line;

	line = ft_get_next_line_many_fds(fd);
	if (line != NULL)
	{
		*trim_line = ft_strtrim(line, "\n\r");
		free (line);
		if (*trim_line == NULL)
			return (false);
	}
	else
		*trim_line = NULL;
	return (true);
}
