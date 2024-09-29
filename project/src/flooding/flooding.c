/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:03:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/29 15:20:39 by gabriel          ###   ########.fr       */
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
	{
		printf("\t\t\tBAD tile_copy\n");
		return (false);
	}
	node = ft_lstnew(copy_tile);
	if (node == NULL)
		return (error_print_critical("Cannot create new node."), false);
//	printf("1 Valor update list tile  x  %ld y %ld size  tovisit %d \n", tile->x, tile->y, ft_lstsize(flood->to_visit));
//	ft_lstdel_front(&flood->to_visit);
//	printf("2 Valor update list tile  x  %ld y %ld size  tovisit %d \n", tile->x, tile->y, ft_lstsize(flood->to_visit));
	ft_lstadd_back(&flood->visited, node);
	//ft_lstadd_front(&flood->visited, node);	
//	printf("3 Valor update list tile  x  %ld y %ld \n", tile->x, tile->y);
	return (true);
}

static	bool	flood_map_next_iteration(t_config cfg, t_flooding *flood)
{
	t_list	*node;
	t_tile	*tile;
	
	flood->is_open = false;
	node = flood->to_visit;
	tile_copy_ptr((t_tile *)node->content, &tile);
	//tile = (t_tile *)node->content;
	
	printf("Nodo tratado x %ld y %ld ; width %ld height %ld tipo %d\n", tile->x, tile->y, cfg.map.width, cfg.map.height ,tile->type);	
	ft_lstdel_front(&flood->to_visit);
	if (tile->type == TILE_UNKNOWN || tile->type == TILE_VOID || \
			tile->y == 0 || tile->y >= cfg.map.height - 1|| \
			tile->x == 0 || tile->x >= cfg.map.width - 1)
	{
//		printf("Nodo que marca el abierto: x %ld y %ld ; width %ld height %ld tipo %d\n", tile->x, tile->y, cfg.map.width, cfg.map.height ,tile->type);	
		flood->is_open = true;
		return (free (tile), true);
	}
//	printf("PRE-BIS Nodo tratado x %ld y %ld ; width %ld height %ld tipo %d\n", tile->x, tile->y, cfg.map.width, cfg.map.height ,tile->type);	
//	if (!flood_update_lists(flood, tile))
//		return (false);
//	printf("BIS Nodo tratado x %ld y %ld ; width %ld height %ld tipo %d\n", tile->x, tile->y, cfg.map.width, cfg.map.height ,tile->type);	
	if(!flood_add_neighbours(cfg, flood, *tile))
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
	while(ft_lstsize(flood.to_visit) > 0)
	{
		if (!flood_map_next_iteration(cfg, &flood))
		{
			printf("ERROR\n");
			return (flood_destroy(&flood), false);
		}
//		printf("FLOOD to visit size: %d visited size : %d \n", ft_lstsize(flood.to_visit), ft_lstsize(flood.visited));
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
