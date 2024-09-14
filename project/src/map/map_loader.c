/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:29:18 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/05 18:50:02 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "map.h"
#include "error.h"
#include "ft_get_next_line.h"
#include "libft.h"

/*
static bool	map_get_size(t_map *map, const char *filename)
{
	int		fd;
	char	*line;
	
	map->width = 0;
	map->height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_perror_critical(), false);	
	line = ft_strdup("");
	if (line == NULL)
		return (error_perror_critical(), false);
	while (line != NULL)
	{
		free (line);
		line = ft_get_next_line_many_fds(fd);
		if (line != NULL)
		{
			map->height++;
			map->width = ft_strlen(line);
		}
	}
	close(fd);
	return (true);
}

static bool	map_malloc(t_map *map)
{
	size_t	i;
	
	map->tiles = (t_tile **)malloc(map->height * sizeof(t_tile *));
	if (map->tiles == NULL)
		return (error_perror_critical(), false);
	i = 0;
	while( i < map->height)
	{
		map->tiles[i] = NULL;
		i++;
	}
	i = 0;
	while( i < map->height)
	{
		map->tiles[i] = (t_tile *)malloc(map->width * sizeof(t_tile));
		if (map->tiles[i] == NULL)
		{
			map_destroy(map);
			return (error_perror_critical(), false);
		}
		i++;
	}
	return (true);
}

bool	map_load(t_map *map, const char *filename)
{
	if (!map_get_size(map, filename))
		return (false);
	if (!map_malloc(map))
		return (false);
	if (!map_parse(map, filename))
		return (false);	
	return (true);	
}
*/