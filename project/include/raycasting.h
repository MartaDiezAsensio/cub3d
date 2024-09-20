/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:03:17 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/20 08:06:57 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "engine.h"
# include "camera.h"

// Funcion para un solo rayo. Input: rayo x, width de pantalla, camara (para direccion)

t_vector    raycasting_new_ray(int x, int w, t_camera camera);
//t_vector    *raycasting_n_ray(int w, t_camera camera);
bool    raycasting_n_ray(int w, t_camera camera, t_vector **rays);
bool    raycasting_paint(t_engine *engine);

#endif