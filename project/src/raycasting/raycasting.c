/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:35:14 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/06 00:32:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "raycasting.h"
#include "error.h"

t_vector	raycasting_new_ray(int x, int w, t_camera camera)
{
	t_vector	ray;
	float		camera_x;
	float		ray_dir_x;
	float		ray_dir_y;

	camera_x = 2.0f * (double)x / ((float)w) - 1.0f;
	ray_dir_x = camera.direction.x + camera.camera_panel.x * camera_x;
	ray_dir_y = camera.direction.y + camera.camera_panel.y * camera_x;
	ray = vector_new_from_values(ray_dir_x, ray_dir_y, false);
	return (ray);
}

bool	raycasting_n_ray(int w, t_camera camera, t_vector **rays)
{
	int	x;

	*rays = (t_vector *)malloc(w * sizeof(t_vector));
	if (*rays == NULL)
	{
		error_perror_critical();
		return (false);
	}
	x = 0;
	while (x < w)
	{
		(*rays)[x] = raycasting_new_ray(x, w, camera);
		x++;
	}
	return (true);
}
