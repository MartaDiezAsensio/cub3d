/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:32:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 23:15:15 by gabriel          ###   ########.fr       */
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

static void	dda_raycasting_init_x(t_dpoint origin, t_vector direction,t_dda_raycasting *dda_ray)
{
	if (direction.x == 0.0f)
		dda_ray->deltaDistX = 1e30;
	else
		dda_ray->deltaDistX = fabs(1 / (float)(direction.x));
	if (direction.x < 0)
	{
		dda_ray->stepX = -1;
		dda_ray->sideDistX = (origin.x - dda_ray->map_point.x) * dda_ray->deltaDistX;
	}
	else
	{
		dda_ray->stepX = 1;
		dda_ray->sideDistX = (dda_ray->map_point.x + 1.0f - origin.x) * dda_ray->deltaDistX;
	}
}

static void	dda_raycasting_init_y(t_dpoint origin, t_vector direction,t_dda_raycasting *dda_ray)
{
	if (direction.y == 0.0f)
		dda_ray->deltaDistY = 1e30;
	else
		dda_ray->deltaDistY = fabs(1 / (float)(direction.y));
	if (direction.y < 0)
	{
		dda_ray->stepY = -1;
		dda_ray->sideDistY = (origin.y - dda_ray->map_point.y) * dda_ray->deltaDistY;
	}
	else
	{
		dda_ray->stepY = 1;
		dda_ray->sideDistY = (dda_ray->map_point.y + 1.0f - origin.y) * dda_ray->deltaDistY;
	}
}

#include <stdio.h>

static void	dda_raycasting_init(t_dpoint origin, t_vector direction, t_dda_raycasting *dda_ray)
{
	dda_ray->map_point.x = origin.x;
	dda_ray->map_point.y = origin.y;
	dda_ray->origin = origin;
	dda_ray->ray = direction;
	dda_raycasting_init_x(origin, direction, dda_ray);
	dda_raycasting_init_y(origin, direction, dda_ray);
}


bool	dda_raycasting_calculate_hit(t_dpoint	origin, t_vector direction, \
			t_map map, t_dda_raycasting *dda_ray)
{
	int hit;

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
	if(dda_ray->side == 0) 	
		dda_ray->perpWallDist = (dda_ray->sideDistX - dda_ray->deltaDistX);
	else
		dda_ray->perpWallDist = (dda_ray->sideDistY - dda_ray->deltaDistY);	

/*

float	compute_dist(t_player *pl, t_ray *r)
{
	if (r->side == 0)
		return ((r->mapx - pl->locx + (1 - r->stepx) / 2) / r->raydirx);
	else
		return ((r->mapy - pl->locy + (1 - r->stepy) / 2) / r->raydiry);
}
*/
/*
	if (dda_ray->side == 0)
		dda_ray->perpWallDist = (dda_ray->map_point.x - dda_ray->origin.x + (1 - dda_ray->stepX) / 2) / dda_ray->ray.x;
	else
		dda_ray->perpWallDist = (dda_ray->map_point.y - dda_ray->origin.y + (1 - dda_ray->stepY) / 2) / dda_ray->ray.y;
//		dda_ray->perpWallDist = (r->mapy - pl->locy + (1 - r->stepy) / 2) / r->raydiry;
*/
	return (true);
}
