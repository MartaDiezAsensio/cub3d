/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:47:52 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/02 17:07:12 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "dda.h"
#include "texture.h"
#include "error.h"

bool    choose_texture(t_engine *engine, t_dda_raycasting *dda_ray, t_texture *texture)
{
    if (dda_ray->side == 0 && dda_ray->ray.x < 0) 
    {
        *texture = engine->textures[TEXTURE_WEST];
        return (true);
    }
    else if (dda_ray->side == 0 && dda_ray->ray.x > 0)
    {
        *texture = engine->textures[TEXTURE_EAST];
        return (true);
    }
    else if (dda_ray->side == 1 && dda_ray->ray.y > 0)
    {
        *texture = engine->textures[TEXTURE_SOUTH];
        return (true);
    }
    else if (dda_ray->side == 1 && dda_ray->ray.y < 0)
    {
        *texture = engine->textures[TEXTURE_NORTH];
        return (true);
    }
    else
        return (error_print_critical("Texture not found."), false);
    return (true);
}
