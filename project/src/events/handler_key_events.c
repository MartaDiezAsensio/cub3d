/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_key_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:05:06 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/25 17:33:22 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "events.h"
#include "engine.h"
#include "vector.h"
#include "map.h"

static void	calculate_new_position(mlx_key_data_t keydata, \
				t_camera camera, t_dpoint *new_point)
{
	t_vector	strafe_dir;

	if (keydata.key == MLX_KEY_W)
	{
		new_point->x = camera.position.x + MOV_SPEED * camera.direction.x;
		new_point->y = camera.position.y + MOV_SPEED * camera.direction.y;
	}
	if (keydata.key == MLX_KEY_S)
	{
		new_point->x = camera.position.x - MOV_SPEED * camera.direction.x;
		new_point->y = camera.position.y - MOV_SPEED * camera.direction.y;
	}
	if (keydata.key == MLX_KEY_A)
	{
		strafe_dir = vector_rotate(camera.direction, -M_PI / 2, false);
		new_point->x = camera.position.x + MOV_SPEED * strafe_dir.x;
		new_point->y = camera.position.y + MOV_SPEED * strafe_dir.y;
	}
	if (keydata.key == MLX_KEY_D)
	{
		strafe_dir = vector_rotate(camera.direction, M_PI / 2, false);
		new_point->x = camera.position.x + MOV_SPEED * strafe_dir.x;
		new_point->y = camera.position.y + MOV_SPEED * strafe_dir.y;
	}
}

static bool	check_new_position(t_map map, t_dpoint new_position)
{
	if (!map_is_inside(map, new_position.x, new_position.y))
		return (false);
	if (map_is_wall(map, new_position.x, new_position.y))
		return (false);
	return (true);
}

static void	move(t_camera *camera, t_dpoint new_position)
{
	camera->position.x = new_position.x;
	camera->position.y = new_position.y;
}

static void	rotate(mlx_key_data_t keydata, t_camera *camera, \
					t_orientations player_orientation)
{
	float	angle;

	angle = 0.0f;
	if (keydata.key == MLX_KEY_RIGHT)
	{
		if (player_orientation == EAST || player_orientation == WEST)
			angle = -ROTATION_ANGLE;
		if (player_orientation == NORTH || player_orientation == SOUTH)
			angle = ROTATION_ANGLE;
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		if (player_orientation == EAST || player_orientation == WEST)
			angle = ROTATION_ANGLE;
		if (player_orientation == NORTH || player_orientation == SOUTH)
			angle = -ROTATION_ANGLE;
	}
	camera->direction = vector_rotate(camera->direction, angle, false);
	camera->camera_panel = vector_rotate(camera->camera_panel, angle, false);
}

void	on_keydown(mlx_key_data_t keydata, void *param)
{
	t_engine	*engine;
	t_dpoint	new_position;

	engine = (t_engine *)param;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S || \
			keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
	{
		calculate_new_position(keydata, engine->camera, &new_position);
		if (check_new_position(engine->cfg->map, new_position))
			move(&engine->camera, new_position);
	}
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT)
		rotate(keydata, &engine->camera, engine->cfg->player_orientation);
	if (keydata.key == MLX_KEY_ESCAPE)
		engine_stop(engine);
}
