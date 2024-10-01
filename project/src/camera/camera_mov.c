/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:29:58 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/30 21:43:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "MLX42/MLX42.h"
#include "camera.h"
#include "map.h"
#include "vector.h"

/*
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
*/

static bool	check_new_position(t_map map, t_dpoint new_position)
{
	if (!map_is_inside(map, new_position.x, new_position.y))
		return (false);
	if (map_cell_is_wall(map, new_position.x, new_position.y))
		return (false);
	return (true);
}

void	camera_move(t_camera *camera, t_map map, t_dpoint new_position)
{
	if (check_new_position(map, new_position))
	{
		camera->position.x = new_position.x;
		camera->position.y = new_position.y;
	}
}

void	camera_rotate(t_camera *camera, float angle)
{
	camera->direction = vector_rotate(camera->direction, angle, false);
	camera->camera_panel = vector_rotate(camera->camera_panel, angle, false);
}
