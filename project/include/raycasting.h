/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:03:17 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/19 20:31:23 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "camera.h"

// Funcion para un solo rayo. Input: rayo x, width de pantalla, camara (para direccion)
t_vector    raycasting_new_ray(int x, int w, t_camera camera);
//t_vector    *raycasting_n_ray(int w, t_camera camera);
bool    raycasting_n_ray(int w, t_camera camera, t_vector **rays);

bool    raycasting_paint(t_engine *engine);

