/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:44:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/12 18:58:26 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "flooding.h"
#include "error.h"

void	flood_destroy(t_flooding *flood)
{
	ft_lstclear(&flood->to_visit, free);
	ft_lstclear(&flood->visited, free);
}

bool	flood_init(t_config cfg, t_flooding *flood)
{
	t_tile	*tile;
	t_list	*node;

	flood->is_open = false;
	flood->visited = NULL;
	flood->to_visit = NULL;
	tile = (t_tile *)malloc(sizeof(t_tile));
	if (tile == NULL)
		return(error_perror_critical(), false);
	*tile = tile_new(cfg.player_position.x, cfg.player_position.y, \
				cfg.map.map[cfg.player_position.x][cfg.player_position.y]);
	node = ft_lstnew(tile);
	if (node == NULL)
	{
		free (tile);
		return(error_perror_critical(), false);
	}
	ft_lstadd_back(&flood->to_visit, node);
	return (true);
}

bool	flood_is_tile_in_list(t_list	*list, t_tile _tile)
{
	t_list	*node;
	t_tile	*tile;

	node = list;
	while (node != NULL)
	{
		tile = (t_tile *)node->content;
		if (tile->x == _tile.x && tile->y == _tile.y)
			return (true);
		node = node->next;
	}
	return (false);
}