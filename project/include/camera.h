/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:35:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/30 21:49:45 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "types.h"
# include "point.h"
# include "vector.h"
# include "map.h"

# define FOV	0.66f
# define ROTATION_SPEED 0.05f
# define MOV_SPEED 0.3f

typedef struct s_camera
{
	t_dpoint	position;
	t_vector	direction;
	t_vector	camera_panel;
} t_camera;

//camera/camera.c
t_camera	camera_new(t_dpoint origin, t_orientations orientation);

//camera/camerea_mov.c
void	camera_move(t_camera *camera, t_map map, t_dpoint new_position);
void	camera_rotate(t_camera *camera, float angle);

#endif
