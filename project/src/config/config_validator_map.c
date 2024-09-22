/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validator_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:49:35 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/22 13:47:49 by mdiez-as         ###   ########.fr       */
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
				cfg->player_position = dpoint_new(i,j);
				cfg->player_orientation = \
							config_map_resolve_orientation(cfg->map.map[i][j]);
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
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
		return(error_print_critical("Cannot find player at map."), false);
	if (!config_map_is_closed(cfg, &is_closed))
		return(error_print_critical("The map is NOT closed."), false);
	printf("Valid map: %d\n", is_closed);
	return (true);
}