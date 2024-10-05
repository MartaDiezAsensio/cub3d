/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:32:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/06 00:30:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "dda.h"

/*
static bool	dda_raycasting_check_hit(t_point point, t_map map)
{
	if ((map.map[point.y][point.x]) == MAP_TILE_WALL)
		return (true);
	return (false);
}
*/

static void	dda_raycasting_init_x(t_dpoint origin, t_vector direction, \
				t_dda_raycasting *dda_ray)
{
	if (direction.x == 0.0f)
		dda_ray->delta_dist_x = 1e30;
	else
		dda_ray->delta_dist_x = fabs(1 / (float)(direction.x));
	if (direction.x < 0)
	{
		dda_ray->step_x = -1;
		dda_ray->side_dist_x = (origin.x - dda_ray->map_point.x) * \
									dda_ray->delta_dist_x;
	}
	else
	{
		dda_ray->step_x = 1;
		dda_ray->side_dist_x = (dda_ray->map_point.x + 1.0f - origin.x) * \
									dda_ray->delta_dist_x;
	}
}

static void	dda_raycasting_init_y(t_dpoint origin, t_vector direction, \
				t_dda_raycasting *dda_ray)
{
	if (direction.y == 0.0f)
		dda_ray->delta_dist_y = 1e30;
	else
		dda_ray->delta_dist_y = fabs(1 / (float)(direction.y));
	if (direction.y < 0)
	{
		dda_ray->step_y = -1;
		dda_ray->side_dist_y = (origin.y - dda_ray->map_point.y) * \
									dda_ray->delta_dist_y;
	}
	else
	{
		dda_ray->step_y = 1;
		dda_ray->side_dist_y = (dda_ray->map_point.y + 1.0f - origin.y) * \
									dda_ray->delta_dist_y;
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

static void	dda_loop(int *hit, t_dda_raycasting *dda, t_map map)
{
	if (dda->side_dist_x < dda->side_dist_y)
	{
		dda->side_dist_x += dda->delta_dist_x;
		dda->map_point.x += dda->step_x;
		dda->side = HIT_X_SIDE;
	}
	else
	{
		dda->side_dist_y += dda->delta_dist_y;
		dda->map_point.y += dda->step_y;
		dda->side = HIT_Y_SIDE;
	}
	if (map_cell_is_wall(map, dda->map_point.x, dda->map_point.y))
		*hit = 1;
}

bool	dda_raycasting_calculate_hit(t_dpoint	origin, t_vector direction, \
			t_map map, t_dda_raycasting *dda_ray)
{
	int	hit;

	hit = 0;
	dda_raycasting_init(origin, direction, dda_ray);
	while (hit == 0)
	{
		dda_loop(&hit, dda_ray, map);
	}
	if (dda_ray->side == HIT_X_SIDE)
		dda_ray->perp_wall_dist = (dda_ray->side_dist_x - \
										dda_ray->delta_dist_x);
	else
		dda_ray->perp_wall_dist = (dda_ray->side_dist_y - \
										dda_ray->delta_dist_y);
	return (true);
}
