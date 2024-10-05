/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_key_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:05:06 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/06 00:06:48 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "events.h"
#include "engine.h"
#include "vector.h"
#include "map.h"

static	t_vector	calculate_strafe_dir(mlx_key_data_t keydata, \
						t_camera camera, t_orientations orientation)
{
	t_vector	strafe_dir;

	if (keydata.key == MLX_KEY_A)
	{
		if (orientation == NORTH || orientation == SOUTH)
			strafe_dir = vector_rotate(camera.direction, -M_PI / 2, false);
		else
			strafe_dir = vector_rotate(camera.direction, M_PI / 2, false);
	}
	if (keydata.key == MLX_KEY_D)
	{
		if (orientation == NORTH || orientation == SOUTH)
			strafe_dir = vector_rotate(camera.direction, M_PI / 2, false);
		else
			strafe_dir = vector_rotate(camera.direction, -M_PI / 2, false);
	}
	return (strafe_dir);
}

static void	calculate_new_position(mlx_key_data_t keydata, \
				t_camera camera, t_dpoint *new_point, \
				t_orientations orientation)
{
	t_vector	strafe_dir;

	if (keydata.key == MLX_KEY_W)
		*new_point = vector_calculate_new_dpoint(camera.position, \
						camera.direction, MOV_SPEED);
	if (keydata.key == MLX_KEY_S)
		*new_point = vector_calculate_new_dpoint(camera.position, \
						camera.direction, -MOV_SPEED);
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
	{
		strafe_dir = calculate_strafe_dir(keydata, camera, orientation);
		*new_point = vector_calculate_new_dpoint(camera.position, strafe_dir, \
						MOV_SPEED);
	}
}

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

void	on_keydown(mlx_key_data_t keydata, void *param)
{
	t_engine	*engine;
	t_dpoint	new_position;
	float		angle;

	engine = (t_engine *)param;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S || \
			keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
	{
		calculate_new_position(keydata, engine->camera, &new_position, \
				engine->cfg->player_orientation);
		camera_move(&engine->camera, engine->cfg->map, new_position);
	}
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT)
	{
		angle = calculate_angle(keydata, engine->cfg->player_orientation);
		camera_rotate(&engine->camera, angle);
	}
	if (keydata.key == MLX_KEY_ESCAPE)
		engine_stop(engine);
}
