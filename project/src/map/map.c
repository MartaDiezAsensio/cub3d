/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:14:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/12 20:09:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"

void	map_destroy(t_map *map)
{
	size_t	i;

	i = 0;
	if (map->map != NULL)
	{
		while (i < map->height)
		{
			if (map->map[i] != NULL)
				free (map->map[i]);
			i++;
		}
		free (map->map);
		map->map = NULL;
		map->height = 0;
		map->width = 0;
	}
}

bool	map_cell_is_player(char tile)
{
	
	if (tile == MAP_TILE_PLAYER_EAST || \
			tile == MAP_TILE_PLAYER_WEST || \
			tile == MAP_TILE_PLAYER_NORTH || \
			tile == MAP_TILE_PLAYER_SOUTH
	)
		return (true);
	return (false);
}
