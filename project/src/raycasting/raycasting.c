/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:35:14 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/17 19:54:04 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "error.h"

// Funcion para un solo rayo. Input: rayo x, width de pantalla, camara (para direccion)
t_vector    raycasting_new_ray(int x, int w, t_camera camera)
{
    t_vector    ray;
    double  cameraX;
    double  rayDirX;
    double  rayDirY;

    cameraX = 2 * x / double(w) -1;
    rayDirX = camera.direction.x + camera.camera_panel.x * cameraX;
    rayDirY = camera.direction.y + camera.camera_panel.y * cameraX;
    ray = vector_new_from_values(rayDirX, rayDirY, true);
    return (ray);
}

bool    raycasting_n_ray(int w, t_camera camera, t_vector **rays)
//t_vector    *raycasting_n_ray(int w, t_camera camera)
{
    int x;
    //t_vector    *ray_array;

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