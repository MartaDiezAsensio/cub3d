/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:03:17 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/20 18:23:02 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "camera.h"

t_vector	raycasting_new_ray(int x, int w, t_camera camera);
//t_vector	*raycasting_n_ray(int w, t_camera camera);
bool	raycasting_n_ray(int w, t_camera camera, t_vector **rays);
bool	raycasting_paint(t_engine *engine);

