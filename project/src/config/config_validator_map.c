/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validator_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:49:35 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/28 00:04:44 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "error.h"
#include "flooding.h"

static	t_orientations	config_map_resolve_orientation(char orientation)
{
	if (orientation == 'N')
		return (NORTH);
	if (orientation == 'S')
		return (SOUTH);
	if (orientation == 'E')
		return (EAST);
	if (orientation == 'W')
		return (WEST);
	return (NONE);
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
			if (cfg->map.map[i][j] == 'N' || cfg->map.map[i][j] == 'S' || \
					cfg->map.map[i][j] == 'W' || cfg->map.map[i][j] == 'E' )
			{
				if (cfg->player_position.x < 0.0f && \
						cfg->player_position.y < 0.0f)
					return(error_print_critical("Found more than one player")\
								, false);
				cfg->player_position = dpoint_new(j,i);
				cfg->player_orientation = \
							config_map_resolve_orientation(cfg->map.map[i][j]);
				return (true);
			}
			j++;
		}
		i++;
	}
	return (error_print_critical("Cannot find player at map."), false);
}

static bool	config_map_is_closed(t_config *cfg, bool *is_closed)
{
	*is_closed = false;

//	if (!flood_map(*cfg, is_closed))
//		return (false);
	*is_closed = true;
	(void)cfg;
	return (true);
}

#include <stdio.h>

bool config_validate_map(t_config *cfg)
{
	bool	is_closed;

	if (!config_map_find_player(cfg))
		return(false);
	if (!config_map_is_closed(cfg, &is_closed))
		return(error_print_critical("The map is NOT closed."), false);
	printf("Valid map: %d\n", is_closed);
	return (true);
}