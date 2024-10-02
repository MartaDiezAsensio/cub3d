/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:14:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/02 20:50:42 by mdiez-as         ###   ########.fr       */
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
			return (false);
	}
	else
		return (false);
}

bool	map_cell_is_valid(char cell)
{
	if (map_cell_is_player(cell) || cell == MAP_TILE_EMPTY || \
			cell == MAP_TILE_VOID || cell == MAP_TILE_WALL)
		return (true);
	return (false);
}
