/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:03:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/22 13:48:16 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "flooding.h"
#include "error.h"
#include "tile.h"

/*
static bool	flood_update_lists(t_flooding *flood, t_tile *tile)
{
	t_tile	*copy_tile;
	t_list	*node;

	if (!tile_copy_ptr(tile, &copy_tile))
		return (false);
	node = ft_lstnew(copy_tile);
	if (node == NULL)
		return (error_print_critical("Cannot create new node."), false);
	ft_lstdel_front(&flood->to_visit);
	ft_lstadd_back(&flood->visited, node);	
	return (true);
}

static	bool	flood_map_next_iteration(t_config cfg, t_flooding *flood)
{
	t_list	*node;
	t_tile	*tile;
	
	flood->is_open = false;
	node = flood->to_visit;
	tile = (t_tile *)node->content;
	
	if (tile->type == TILE_UNKNOWN || tile->type == TILE_VOID || \
			tile->y == 0 || tile->y >= cfg.map.height || \
			tile->x == 0 || tile->y >= cfg.map.width)
	{
		printf("Nodo que marca el abierto: x %ld y %ld ; width %ld height %ld tipo %d\n", tile->x, tile->y, cfg.map.width, cfg.map.height ,tile->type);	
		flood->is_open = true;
		return (true);
	}
	if(!flood_add_neighbours(cfg, flood, *tile))
		return (false);
	if (!flood_update_lists(flood, tile))
		return (false);
	return (true);
}

bool	flood_map(t_config cfg, bool *is_closed)
{
	t_flooding	flood;

	if (!flood_init(cfg, &flood))
		return (false);
	while(ft_lstsize(flood.to_visit) > 0)
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
*/