/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:35:03 by gabriel           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/26 16:22:39 by mdiez-as         ###   ########.fr       */
=======
/*   Updated: 2024/09/25 20:18:29 by mdiez-as         ###   ########.fr       */
>>>>>>> 7291751d225f7456b05386a565c5c659ee9f72e2
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
	t_dpoint	position;
	t_vector	direction;
	t_vector	camera_panel;
} t_camera;

t_camera	camera_new(t_dpoint origin, t_orientations orientation);

#endif
