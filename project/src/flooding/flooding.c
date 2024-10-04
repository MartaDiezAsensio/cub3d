/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:03:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 18:32:54 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "flooding.h"
#include "error.h"
#include "tile.h"

#include <stdio.h>

static bool	flood_update_lists(t_flooding *flood, t_tile *tile)
{
	t_tile	*copy_tile;
	t_list	*node;

	if (!tile_copy_ptr(tile, &copy_tile))
		return (false);
	node = ft_lstnew(copy_tile);
	if (node == NULL)
		return (error_print_critical("Cannot create new node."), false);
	ft_lstadd_back(&flood->visited, node);
	return (true);
}

static	bool	flood_map_next_iteration(t_config cfg, t_flooding *flood)
{
	t_list	*node;
	t_tile	*tile;

	flood->is_open = false;
	node = flood->to_visit;
	tile_copy_ptr((t_tile *)node->content, &tile);
	ft_lstdel_front(&flood->to_visit);
	if (tile->type == TILE_UNKNOWN || tile->type == TILE_VOID || \
			tile->y == 0 || tile->y >= cfg.map.height - 1 || \
			tile->x == 0 || tile->x >= cfg.map.width - 1)
	{
		flood->is_open = true;
		return (free (tile), true);
	}
	if (!flood_add_neighbours(cfg, flood, *tile))
		return (free (tile), false);
	if (!flood_update_lists(flood, tile))
		return (free (tile), false);
	return (free (tile), true);
}

bool	flood_map(t_config cfg, bool *is_closed)
{
	t_flooding	flood;

	if (!flood_init(cfg, &flood))
		return (false);
	while (ft_lstsize(flood.to_visit) > 0)
	{
		if (!flood_map_next_iteration(cfg, &flood))
			return (flood_destroy(&flood), false);
		if (flood.is_open)
		{
			*is_closed = false;
			flood_destroy(&flood);
			error_print_critical("The map is NOT closed where the player is.");
			return (true);
		}
	}
	flood_destroy(&flood);
	*is_closed = true;
	return (true);
}
