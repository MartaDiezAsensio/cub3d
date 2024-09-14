/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:48:58 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/12 23:02:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tile.h"
#include "map.h"
#include "error.h"
#include "screen.h"

t_tile	tile_new(size_t _x, size_t _y, char _type)
{
	t_tile	tile;

	tile.x = _x;
	tile.y = _y;
	tile.type = tile_determine_type(_type);
	return (tile);
}

t_tile_type tile_determine_type(char tile)
{
	if (tile == MAP_TILE_EMPTY)
		return (TILE_EMPTY);
	if (tile == MAP_TILE_WALL)
		return (TILE_WALL);
	if (map_cell_is_player(tile))
		return (TILE_PLAYER);
	if (tile == MAP_TILE_VOID)
		return (TILE_VOID);
	return (TILE_UNKNOWN);
}

bool	tile_copy_ptr(t_tile *origin, t_tile **destiny)
{
	*destiny = (t_tile *)malloc(sizeof(t_tile));
	if (*destiny == NULL)
		return (false);
	(*destiny)->type = origin->type;
	(*destiny)->x = origin->x;
	(*destiny)->y = origin->y;
	return (true);	
}

bool	tile_is_player(t_tile tile)
{
	if (tile.type == TILE_PLAYER_EAST || \
			tile.type == TILE_PLAYER_WEST || \
			tile.type == TILE_PLAYER_NORTH || \
			tile.type == TILE_PLAYER_SOUTH || \
			tile.type == TILE_PLAYER
	)
		return (true);
	return (false);
}

int tile_node_compare(void *c1, void *c2)
{
	t_tile	*t1;
	t_tile	*t2;

	t1 = (t_tile*) c1;
	t2 = (t_tile*) c2;

	if (t1->x == t2->x && t1->y == t2->y && t1->type == t2->type)
		return (0);
	return (1);
}