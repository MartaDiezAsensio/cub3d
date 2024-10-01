/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:47:52 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/27 17:00:32 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

t_texture choose_texture(t_dda_raycasting *dda_ray, t_vector *ray)
{
    t_texture   texture;
    
    if (dda_ray->side == 0 && ray->x < 0) // ray.dirX
        texture =  MAP_TEXTURE_NORTH;
    else if (dda_ray->side == 0 && ray->x > 0)
        texture =  MAP_TEXTURE_SOUTH;
    else if (dda_ray->side == 1 && ray->y > 0)
        texture =  MAP_TEXTURE_EAST;
    else if (dda_ray->side == 1 && ray->y < 0)
        texture =  MAP_TEXTURE_WEST;
    else
        //error
    return (texture);
}
