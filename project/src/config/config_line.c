/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:41:11 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/08 19:26:51 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_get_next_line.h"
#include "map.h"
#include "libft.h"
#include "error.h"

bool	config_line_is_map(const char *line)
{
	if (map_cell_is_valid(line[0]))
		return (true);
	return (false);
}

bool	config_line_is_color(const char *line)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \t");
	if (trimmed == NULL)
		return (error_perror_critical(), false);
	if (ft_strncmp(trimmed, "F ", 2) == 0 || ft_strncmp(trimmed, "C ", 2) == 0)
		return (free(trimmed) ,true);
	return (free(trimmed), false);
}

bool	config_line_is_texture(const char *line)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \t");
	if (trimmed == NULL)
		return (error_perror_critical(), false);
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		return (free(trimmed), true);
	if (ft_strncmp(trimmed, "SO ", 3) == 0)
		return (free(trimmed), true);
	if (ft_strncmp(trimmed, "WE ", 3) == 0)
		return (free(trimmed), true);
	if (ft_strncmp(trimmed, "EA ", 3) == 0)
		return (free(trimmed), true);
	return (free(trimmed), false);
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
