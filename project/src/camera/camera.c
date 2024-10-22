/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:43:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 22:21:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"


t_vector	camera_init_screen_plan(t_orientations orientation)
{	
	t_vector error;

	error = vector_new_from_values(999.9, 999.9, false);
	
	if (orientation == NORTH)
		return (vector_new_from_values(FOV, 0.0f, false));
	if (orientation == SOUTH)
		return (vector_new_from_values(-FOV, 0.0f, false));
	if (orientation == WEST)
		return (vector_new_from_values(0.0f, FOV, false));
	if (orientation == EAST)
		return (vector_new_from_values(0.0f,-FOV, false));
	return (error);
}

t_camera	camera_new(t_dpoint origin, t_orientations orientation)
{
	t_camera	camera;

	camera.position = origin;
	if (orientation == NORTH)
		camera.direction = vector_new_from_values(0.0f,-1.0f, false);
	if (orientation == SOUTH)
		camera.direction = vector_new_from_values(0.0f, 1.0f, false);
	if (orientation == WEST)
		camera.direction = vector_new_from_values(-1.0f, 0.0f, false);
	if (orientation == EAST)
		camera.direction = vector_new_from_values(1.0f,0.0f, false);
	camera.camera_panel = camera_init_screen_plan(orientation);
	return (camera);

}
