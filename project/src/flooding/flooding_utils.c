/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:44:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 18:24:13 by greus-ro         ###   ########.fr       */
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
		return (error_perror_critical(), false);
	*tile = tile_new(cfg.player_position.x, cfg.player_position.y, \
				cfg.map.map[(int)cfg.player_position.y] \
							[(int)cfg.player_position.x]);
	node = ft_lstnew(tile);
	if (node == NULL)
	{
		free (tile);
		return (error_perror_critical(), false);
	}
	ft_lstadd_back(&flood->to_visit, node);
	return (true);
}
