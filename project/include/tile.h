/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:32:39 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/12 20:55:19 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	TILE_H
# define TILE_H

# include "types.h"
typedef enum e_tile_type
{
	TILE_EMPTY,
	TILE_PLAYER,
	TILE_PLAYER_EAST,
	TILE_PLAYER_WEST,
	TILE_PLAYER_NORTH,
	TILE_PLAYER_SOUTH,
	TILE_WALL,
	TILE_VOID,
	TILE_UNKNOWN
}	t_tile_type;

typedef struct s_tile
{
	size_t		x;
	size_t		y;
	t_tile_type	type;

}	t_tile;

t_tile		tile_new(size_t _x, size_t _y, char _type);
t_tile_type tile_determine_type(char tile);
bool		tile_copy_ptr(t_tile *origin, t_tile **destinty);
bool		tile_is_player(t_tile tile);
int			tile_node_compare(void *c1, void *c2);

#endif