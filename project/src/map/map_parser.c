/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:33:26 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/05 20:15:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "error.h"
#include "map.h"
#include "tile.h"
#include "libft.h"
#include "ft_get_next_line.h"

/*
static bool map_parse_line(t_map *map, const char *line, size_t num_line)
{
	size_t		total;
	size_t		i;
	char		*tiles;
	t_tile_type	tile_type;

	total = ft_strlen(line);
	if (map->width != total)
		return (error_print_critical("Error: The map is not rectangular / Squared"), false);
	i = 0;
	while (i < total)
	{
		tile_type = map_determine_tile_type(line[i]);
		if (tile_type == TILE_UNKNOWN)
			return (error_print_critical("Error: Unkonwn tile in map"), false);
		//tiles[i] = tile_new(i, num_line, tile_type);
		map->map[num_line] = ft_strdup(line);
		if (map->map[num_line] == NULL)
			return (error_perror_critical() , false);
		i++;
	}
	return (true);
}

static bool map_parse_file(t_map *map, int fd)
{
	char	*line;
	size_t	i;
	
	line = ft_strdup("");
	if (line == NULL)
		return (error_perror_critical(), false);
	i = 0;
	while (line != NULL)
	{
		free (line);
		line = ft_get_next_line_many_fds(fd);
		if (line != NULL)
		{
			if (map->width != ft_strlen(line))
				return (free (line), error_print_critical("Error: The map is not rectangular / Squared"), false);
			if (!map_parse_line(map, line, i))
				return (false);
			i++;
		}
	}
	return (true);
}

bool	map_parse(t_map *map, const char *filename)
{
	int		fd;

	if (map->map == NULL)
		return (error_print_critical("Error: at memory malloc."), false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_perror_critical(), false);
	if (!map_parse_file(map, fd))
		return (close (fd), false);
	close (fd);	
	return (true);
}
*/