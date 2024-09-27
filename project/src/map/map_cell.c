/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:14:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/28 01:32:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"

bool	map_cell_is_player(char cell)
{
	if (cell == MAP_TILE_PLAYER_EAST || \
			cell == MAP_TILE_PLAYER_WEST || \
			cell == MAP_TILE_PLAYER_NORTH || \
			cell == MAP_TILE_PLAYER_SOUTH
	)
		return (true);
	return (false);
}

bool	map_cell_is_wall(t_map map, int col, int row)
{
	if (map_is_inside(map, col, row))
	{
		if (map.map[row][col] == MAP_TILE_WALL)
			return (true);
		else
			return(false);
	}
	else
		return (false);
}

bool	map_cell_is_valid(char cell)
{
	if (map_cell_is_player(cell) || cell == MAP_TILE_EMPTY || cell == MAP_TILE_VOID || cell == MAP_TILE_WALL)
		return (true);
	return (false);
}