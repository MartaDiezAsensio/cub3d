/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:29:58 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/06 21:53:29 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "MLX42/MLX42.h"
#include "camera.h"
#include "map.h"
#include "vector.h"

/* In this function we check if the new position is valid. */
static bool	check_new_position(t_map map, t_dpoint new_position)
{
	if (!map_is_inside(map, new_position.x, new_position.y))
		return (false);
	if (map_cell_is_wall(map, new_position.x, new_position.y))
		return (false);
	return (true);
}

/* We move the camera position to a new position.*/
void	camera_move(t_camera *camera, t_map map, t_dpoint new_position)
{
	if (check_new_position(map, new_position))
	{
		camera->position.x = new_position.x;
		camera->position.y = new_position.y;
	}
}

/* We rotate the camera direction and panel to the angle rads.*/
void	camera_rotate(t_camera *camera, float angle)
{
	camera->direction = vector_rotate(camera->direction, angle, false);
	camera->camera_panel = vector_rotate(camera->camera_panel, angle, false);
}
