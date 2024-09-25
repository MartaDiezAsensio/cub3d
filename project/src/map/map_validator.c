/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:43:22 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/25 23:42:13 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "map.h"
#include "libft.h"

static bool	check_line_is_wall_or_empty(char *line_map)
{
	size_t	x;

	x = 0;
	while (line_map[x] != '\0')
	{
		if (line_map[x] != MAP_TILE_VOID || line_map[x] != MAP_TILE_WALL)
			return (false);
		x++;
	}
	return (true);
}


/*
As such, I came up with a few map validation rules. Assume that we are scanning the map from top to bottom, left to right :

    Ignore all leading whitespaces.
    If the current row is the 0th row or the final row, only accept '1's and ' 's.
        else, The first and final character should always be a '1'.
    In the case of any non leading whitespaces, the only acceptable characters adjacent to the space are '1's or ' 's.
    If strlen(curr_row) > strlen(row_on_top) && current col > strlen(row_on_top), current character should be '1'
    If strlen(curr_row) > strlen(row_on_bottom) && current col > strlen(row_on_bottom), current character should be '1'

Those rules should pass all the map requirements given.
*/
bool	map_validator(t_map *map)
{
	size_t	x;
	size_t	y;
	char	*line;
	size_t	len;

	if (!check_line_is_wall_or_empty(map->map[0]) || \
			!check_line_is_wall_or_empty(map->map[map->height - 1]))
		return (false);
	y = 1;
	while (y < map->height - 1)
	{
		line = ft_strtrim(map->map[y]," ");
		len = ft_strlen(map->map[y]);
		if (line[0] != MAP_TILE_WALL || line[len - 1] != MAP_TILE_WALL)
			return(free(line), false);
		x = 1;
		while(line[x] != '\0')
		{
			
			x++;
		}
		free (line);
		y++;
	}
	return (true);
}