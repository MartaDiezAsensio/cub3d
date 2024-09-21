/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:43:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/21 19:50:49 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"


t_vector	camera_init_screen_plan(t_orientations orientation)
{	
	/*
	if (orientation == NORTH || orientation == SOUTH)
		return (vector_new_from_values(FOV, 0.0f, false));
	else
		return (vector_new_from_values(0.0f, FOV, false));
	*/

	if (orientation == NORTH)
		return (vector_new_from_values(FOV, 0.0f, false));
	if (orientation == SOUTH)
		return (vector_new_from_values(-FOV, 0.0f, false));
	if (orientation == WEST)
		return (vector_new_from_values(0.0f, FOV, false));
	//if (orientation == EAST)
	return (vector_new_from_values(0.0f,-FOV, false));

}

#include <stdio.h>
t_camera	camera_new(t_point origin, t_orientations orientation)
{
	t_camera	camera;

	camera.position = origin;
	printf("%d Orientation!\n", orientation);
	if (orientation == NORTH)
	{
		printf("%d NORTH!\n", orientation);
		camera.direction = vector_new_from_values(0.0f,-1.0f, true);
	if (orientation == SOUTH)
		camera.direction = vector_new_from_values(0.0f, 1.0f, true);
	if (orientation == WEST)
		camera.direction = vector_new_from_values(-1.0f, 0.0f, true);
	if (orientation == EAST)
		camera.direction = vector_new_from_values(1.0f,0.0f, true);
		/* TODO: agregar las direcciones del vector direction.*/
	}
	camera.camera_panel = camera_init_screen_plan(orientation);
	return (camera);

}
