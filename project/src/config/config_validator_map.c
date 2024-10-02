/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validator_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:49:35 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/02 20:16:23 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "error.h"
#include "flooding.h"

static void	config_map_save_player_data(t_config *cfg, size_t i, size_t j)
{
	cfg->player_position = dpoint_new(j, i);
	if (cfg->map.map[i][j] == MAP_TILE_PLAYER_NORTH)
		cfg->player_orientation = NORTH;
	if (cfg->map.map[i][j] == MAP_TILE_PLAYER_SOUTH)
		cfg->player_orientation = SOUTH;
	if (cfg->map.map[i][j] == MAP_TILE_PLAYER_EAST)
		cfg->player_orientation = EAST;
	if (cfg->map.map[i][j] == MAP_TILE_PLAYER_WEST)
		cfg->player_orientation = WEST;
}

static bool	config_is_player_position_uninit(t_dpoint player_position)
{
	return (player_position.x < 0.0f && player_position.y < 0.0f);
}

bool	config_map_find_player(t_config *cfg)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cfg->map.map[i] != NULL)
	{
		j = 0;
		while (cfg->map.map[i][j] != '\0')
		{
			if (!map_cell_is_valid(cfg->map.map[i][j]))
				return (error_print_critical("Found not valid char."), false);
			if (map_cell_is_player(cfg->map.map[i][j]))
			{
				if (!config_is_player_position_uninit(cfg->player_position))
					return (error_print_critical ("Found 1+ player"), false);
				config_map_save_player_data(cfg, i, j);
			}
			j++;
		}
		i++;
	}
	if (!config_is_player_position_uninit(cfg->player_position))
		return (true);
	return (error_print_critical("Cannot find player at map."), false);
}

static bool	config_map_is_closed(t_config *cfg, bool *is_closed)
{
	*is_closed = false;
	if (!flood_map(*cfg, is_closed))
		return (false);
	return (true);
}

bool	config_validate_map(t_config *cfg)
{
	bool	is_closed;

	if (!config_map_find_player(cfg))
		return (false);
	if (!config_map_is_closed(cfg, &is_closed) || !is_closed)
		return (false);
	return (true);
}
