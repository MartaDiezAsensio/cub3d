/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:32:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/02 20:24:16 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "dda.h"
#include <stdio.h>

static bool	dda_raycasting_check_hit(t_point point, t_map map)
{
	if ((map.map[point.y][point.x]) == MAP_TILE_WALL)
		return (true);
	return (false);
}

static void	dda_raycasting_init_x(t_dpoint origin, t_vector direction, \
				t_dda_raycasting *dda_ray)
{
	if (direction.x == 0.0f)
		dda_ray->deltaDistX = 1e30;
	else
		dda_ray->deltaDistX = fabs(1 / (float)(direction.x));
	if (direction.x < 0)
	{
		dda_ray->stepX = -1;
		dda_ray->sideDistX = (origin.x - dda_ray->map_point.x) * \
					dda_ray->deltaDistX;
	}
	else
	{
		dda_ray->stepX = 1;
		dda_ray->sideDistX = (dda_ray->map_point.x + 1.0f - origin.x) * \
					dda_ray->deltaDistX;
	}
}

static void	dda_raycasting_init_y(t_dpoint origin, t_vector direction, \
			t_dda_raycasting *dda_ray)
{
	if (direction.y == 0.0f)
		dda_ray->deltaDistY = 1e30;
	else
		dda_ray->deltaDistY = fabs(1 / (float)(direction.y));
	if (direction.y < 0)
	{
		dda_ray->stepY = -1;
		dda_ray->sideDistY = (origin.y - dda_ray->map_point.y) * \
					dda_ray->deltaDistY;
	}
	else
	{
		dda_ray->stepY = 1;
		dda_ray->sideDistY = (dda_ray->map_point.y + 1.0f - origin.y) * \
				dda_ray->deltaDistY;
	}
}

static void	dda_raycasting_init(t_dpoint origin, t_vector direction, \
			t_dda_raycasting *dda_ray)
{
	dda_ray->map_point.x = origin.x;
	dda_ray->map_point.y = origin.y;
	dda_ray->origin = origin;
	dda_ray->ray = direction;
	dda_raycasting_init_x(origin, direction, dda_ray);
	dda_raycasting_init_y(origin, direction, dda_ray);
}

// Function has more than 25 lines
bool	dda_raycasting_calculate_hit(t_dpoint	origin, t_vector direction, \
			t_map map, t_dda_raycasting *dda_ray)
{
	int	hit;

	hit = 0;
	dda_raycasting_init(origin, direction, dda_ray);
	while (hit == 0)
	{
		if (dda_ray->sideDistX < dda_ray->sideDistY)
		{
			dda_ray->sideDistX += dda_ray->deltaDistX;
			dda_ray->map_point.x += dda_ray->stepX;
			dda_ray->side = 0;
		}
		else
		{
			dda_ray->sideDistY += dda_ray->deltaDistY;
			dda_ray->map_point.y += dda_ray->stepY;
			dda_ray->side = 1;
		}
		if (dda_raycasting_check_hit(dda_ray->map_point, map))
			hit = 1;
	}
	if (dda_ray->side == 0)
		dda_ray->perpWallDist = (dda_ray->sideDistX - dda_ray->deltaDistX);
	else
		dda_ray->perpWallDist = (dda_ray->sideDistY - dda_ray->deltaDistY);
	return (true);
}
