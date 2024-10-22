/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:28:10 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/30 19:21:15 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "tile.h"
# include "types.h"

# define MAP_TILE_WALL 			'1'
# define MAP_TILE_EMPTY			'0'
# define MAP_TILE_PLAYER_NORTH	'N'
# define MAP_TILE_PLAYER_SOUTH	'S'
# define MAP_TILE_PLAYER_EAST	'E'
# define MAP_TILE_PLAYER_WEST	'W'
# define MAP_TILE_VOID			' '

typedef struct s_map
{
	size_t	height;
	size_t	width;
	char	**map;

}	t_map;

//map.c
t_tile_type map_determine_tile_type(char tile);
void	map_destroy(t_map *map);
bool	map_is_inside(t_map map, int col, int row);
bool	map_normalize(t_map *map);

//map_cell.c
bool	map_cell_is_player(char tile);
bool	map_cell_is_wall(t_map map, int col, int row);
bool	map_cell_is_valid(char cell);

//map_loader.c
bool	map_load(t_map *map, const char *filename);

//map_parser.c
bool	map_parse(t_map *map, const char *filename);

//map_validator.c
bool	map_validator(t_map map);

#endif
