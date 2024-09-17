/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:35:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/17 18:04:51 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "types.h"
# include "point.h"
# include "vector.h"

# define FOV	0.66f

typedef struct s_camera
{
	t_point		position;
	t_vector	direction;
	t_vector	camera_panel;
} t_camera;

t_camera	camera_new(t_point origin, t_orientations orientation);

#endif