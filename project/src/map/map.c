/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:14:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/29 23:20:32 by gabriel          ###   ########.fr       */
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

bool	map_is_inside(t_map map, int col, int row)
{
	if (col < 0 || col >= (int)map.width)
		return (false);
	if (row < 0 || row >= (int)map.height)
		return (false);
	return (true);
}
