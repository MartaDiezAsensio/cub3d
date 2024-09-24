/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding_neighbours.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:32:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/22 13:46:49 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "flooding.h"
#include "error.h"

/*
static bool	flood_get_neighbour(t_config cfg, t_list **node, int x, int y)
{
	t_tile	*tile;
	char	tile_type;

	*node = NULL;
	if (x >= 0 && (size_t)x < cfg.map.width)
	{
		if (y >= 0 && (size_t)y < cfg.map.height)
		{
			tile_type = cfg.map.map[x][y];
			if (tile_type != MAP_TILE_WALL)
			{
				tile = (t_tile *)malloc(sizeof(t_tile));
				if (tile == NULL)
					return (error_perror_critical(), false);
				*tile = tile_new(x, y, cfg.map.map[x][y]);
				*node = ft_lstnew(tile);
				if (*node == NULL)
					return (error_print_critical("Cannot create node."), false);
			}
		}
	}
	return (true);
}

static bool	flood_add_neighbour(t_config cfg, t_flooding *flood, int x, int y)
{
	t_list	*node;

	if (!flood_get_neighbour(cfg, &node, x, y))
		return (false);
	if (node != NULL)
	{
		if (ft_lstcontains(flood->visited, node->content, tile_node_compare) == 0)
			ft_lstadd_back(&flood->to_visit, node);
		else
			ft_lstdelone(node, free);
	}
	return (true);
}

bool	flood_add_neighbours(t_config cfg, t_flooding *flood, t_tile tile)
{
	if (!flood_add_neighbour(cfg, flood, tile.x + 1 , tile.y))
		return (false);
	if (!flood_add_neighbour(cfg, flood, tile.x - 1 , tile.y))
		return (false);
	if (!flood_add_neighbour(cfg, flood, tile.x, tile.y + 1))
		return (false);
	if (!flood_add_neighbour(cfg, flood, tile.x, tile.y - 1))
		return (false);
	return (true);	
}
*/