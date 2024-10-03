/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_mouse_event.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:04:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 23:30:46 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "engine.h"

#include <stdio.h>

/*

static float	calculate_angle(mlx_key_data_t keydata, \
					t_orientations player_orientation)
{
	float	angle;

	angle = 0.0f;
	if (keydata.key == MLX_KEY_RIGHT)
	{
		if (player_orientation == EAST || player_orientation == WEST)
			angle = -ROTATION_SPEED;
		if (player_orientation == NORTH || player_orientation == SOUTH)
			angle = ROTATION_SPEED;
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		if (player_orientation == EAST || player_orientation == WEST)
			angle = ROTATION_SPEED;
		if (player_orientation == NORTH || player_orientation == SOUTH)
			angle = -ROTATION_SPEED;
	}
	return (angle);
}


*/

static float	calculate_angle(double deltaX, t_orientations orientation)
{
	float	angle;

	angle = 0.0f;
	if (deltaX < 0.0f)
	{
		if (orientation == EAST || orientation == WEST)
			angle = -ROTATION_SPEED;
		if (orientation == NORTH || orientation == SOUTH)
			angle = ROTATION_SPEED;
	}
	if (deltaX > 0.0f)
	{
		if (orientation == EAST || orientation == WEST)
			angle = ROTATION_SPEED;
		if (orientation == NORTH || orientation == SOUTH)
			angle = -ROTATION_SPEED;
	}
	return (angle);
}

#include <stdio.h>
//void (*mlx_cursorfunc)(double xpos, double ypos, void* param)
void	on_mouse_move_event(double xpos, double ypos, void* param)
{
	t_engine	*engine;
	float		angle;

	engine = (t_engine *)param;
//	printf("mouse: x %f  y %f\n", xpos, ypos);
	angle = calculate_angle(engine->screen.mouse_position.x - xpos, \
				engine->cfg->player_orientation);
	(void)angle;
	(void)ypos;
	printf("\tMOVIMIENTO!!! angle: %f, pixels: mouse %f %f\n", angle, engine->screen.mouse_position.x, xpos);
	camera_rotate(&engine->camera, angle);
	engine->screen.mouse_position.x = xpos;
	engine->screen.mouse_position.y = ypos;
}