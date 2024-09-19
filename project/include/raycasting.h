/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:03:17 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/17 21:56:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

// Funcion para un solo rayo. Input: rayo x, width de pantalla, camara (para direccion)
t_vector	raycasting_new_ray(int x, int w, t_camera camera);
bool		raycasting_n_ray(int w, t_camera camera, t_vector **rays);
