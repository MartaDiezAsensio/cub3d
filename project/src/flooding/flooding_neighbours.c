/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding_neighbours.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:32:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 18:27:43 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "flooding.h"
#include "error.h"

static bool	flood_get_neighbour(t_config cfg, t_list **node, int x, int y)
{
	t_tile	*tile;
	char	tile_type;

	*node = NULL;
	if (x >= 0 && (size_t)x < cfg.map.width)
	{
		if (y >= 0 && (size_t)y < cfg.map.height)
		{
			tile_type = cfg.map.map[y][x];
			if (tile_type != MAP_TILE_WALL)
			{
				tile = (t_tile *)malloc(sizeof(t_tile));
				if (tile == NULL)
					return (error_perror_critical(), false);
				*tile = tile_new(x, y, cfg.map.map[y][x]);
				*node = ft_lstnew(tile);
				if (*node == NULL)
					return (error_print_critical("Cannot create node."), false);
			}
		}
	}
	return (true);
}

/*
	Here we add the neighbour ONLY if it is not in the visited list and 
	it is NOT in the to visit list.
*/
static bool	flood_add_neighbour(t_config cfg, t_flooding *flood, int x, int y)
{
	t_list	*node;

	if (!flood_get_neighbour(cfg, &node, x, y))
		return (false);
	if (node != NULL)
	{
		if (ft_lstcontains(flood->visited, node->content, \
					tile_node_compare) == 0 && \
					ft_lstcontains(flood->to_visit, node->content, \
					tile_node_compare) == 0)
			ft_lstadd_back(&flood->to_visit, node);
		else
			ft_lstdelone(node, free);
	}
	return (true);
}

/*
	We check also diags
*/
bool	flood_add_neighbours(t_config cfg, t_flooding *flood, t_tile tile)
{
	if (!flood_add_neighbour(cfg, flood, tile.x + 1, tile.y))
		return (false);
	if (!flood_add_neighbour(cfg, flood, tile.x - 1, tile.y))
		return (false);
	if (!flood_add_neighbour(cfg, flood, tile.x, tile.y + 1))
		return (false);
	if (!flood_add_neighbour(cfg, flood, tile.x, tile.y - 1))
		return (false);
	if (!flood_add_neighbour(cfg, flood, tile.x + 1, tile.y - 1))
		return (false);
	if (!flood_add_neighbour(cfg, flood, tile.x + 1, tile.y + 1))
		return (false);
	if (!flood_add_neighbour(cfg, flood, tile.x - 1, tile.y - 1))
		return (false);
	if (!flood_add_neighbour(cfg, flood, tile.x - 1, tile.y - 1))
		return (false);
	return (true);
}
