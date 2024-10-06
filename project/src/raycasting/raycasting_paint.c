/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_paint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:15:21 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/06 21:04:21 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "vector.h"
#include "dda.h"
#include "error.h"

/*
	Here we calculate the number of pixels that we have to paint corresponding
	to the wall
*/
static int	raycasting_calculate_wall(double distance, int screen_height)
{
	int	line_height;

	line_height = (int)(screen_height / distance);
	return (line_height);
}

/*
	for each column of pixels, we throw  a ray from the camera/player position
	and we calculate the axis where the ray hits.

	We get the number of pixelsof wall and then we have to render the column, 
	ceiling, wall and floor.
*/
bool	raycasting_paint(t_engine *engine)
{
	size_t				x;
	t_vector			ray_direction;
	int					num_pixels_wall;
	t_dda_raycasting	dda;

	x = 0;
	while (x < engine->screen.x)
	{
		ray_direction = raycasting_new_ray(x, engine->screen.x, \
							engine->camera);
		if (!dda_raycasting_calculate_hit(engine->camera.position, \
				ray_direction, engine->cfg->map, &dda))
			return (error_print_critical("DDA did not worked"), false);
		num_pixels_wall = raycasting_calculate_wall(dda.perp_wall_dist, \
							engine->screen.y);
		engine_render_column(*engine, x, num_pixels_wall, dda);
		x++;
	}
	return (true);
}
