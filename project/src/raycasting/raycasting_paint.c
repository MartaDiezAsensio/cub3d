/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_paint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:15:21 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/01 19:50:19 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "vector.h"
#include "dda.h"
#include "error.h"

static int  raycasting_calculate_wall(double distance, int screen_height)
{
	int line_height;

	line_height = (int) (screen_height / distance);
	return (line_height);
}

/*
#include <math.h>

static double  get_cos_between_vectors(t_vector camera_dir, t_vector ray_dir)
{
	//https://www.geeksforgeeks.org/angle-between-two-vectors-formula/
	double cosinus;
	
	cosinus = (camera_dir.x * ray_dir.x + camera_dir.y * ray_dir.y)  / (camera_dir.modulus * ray_dir.modulus);
	return (cosinus);
}
*/

bool    raycasting_paint(t_engine *engine)
{
	size_t				x;
	t_vector			ray_direction;
	int					num_pixels_wall;
	t_dda_raycasting	dda;

	x = 0;
	while(x < engine->screen.x)
	{
		ray_direction = raycasting_new_ray(x, engine->screen.x, engine->camera); 		
		if (!dda_raycasting_calculate_hit(engine->camera.position, ray_direction, engine->cfg->map, &dda))
			return (error_print_critical("DDA did not worked"), false);
		num_pixels_wall = raycasting_calculate_wall(dda.perpWallDist, engine->screen.y);
		engine_render_column(*engine, x, num_pixels_wall, dda);
		x++;
	}
	return (true);
}
