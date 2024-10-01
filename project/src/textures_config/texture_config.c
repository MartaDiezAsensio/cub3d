/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:47:52 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/01 20:44:46 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "dda.h"
#include "textures.h"
#include "error.h"
#include <stdio.h>

bool    choose_texture(t_engine *engine, t_dda_raycasting *dda_ray, t_texture *texture)
{
    printf("\t\t\tDireccion norte %p \n",&engine->textures[TEXTURE_NORTH]);
    printf("\t\t\tDireccion sur %p \n", &engine->textures[TEXTURE_SOUTH]);
    printf("\t\t\tDireccion este %p \n", &engine->textures[TEXTURE_EAST]);
    printf("\t\t\tDireccion oeste %p \n", &engine->textures[TEXTURE_WEST]);
    if (dda_ray->side == 0 && dda_ray->ray.x < 0) 
    {
        printf("\t\t\tDireccion oeste %p \n", &engine->textures[TEXTURE_WEST]);
        texture =  &engine->textures[TEXTURE_WEST];
        printf("\t\t\t POST %p\n", texture);
        return (true);
    }
    else if (dda_ray->side == 0 && dda_ray->ray.x > 0)
    {
        printf("\t\t\tDireccion este %p \n", &engine->textures[TEXTURE_EAST]);
        texture = &engine->textures[TEXTURE_EAST];
        return (true);
    }
    else if (dda_ray->side == 1 && dda_ray->ray.y > 0)
    {
        printf("\t\t\tDireccion sur %p \n", &engine->textures[TEXTURE_SOUTH]);
        texture = &engine->textures[TEXTURE_SOUTH];
        return (true);
    }
    else if (dda_ray->side == 1 && dda_ray->ray.y < 0)
    {
        printf("\t\t\tDireccion norte %p \n",&engine->textures[TEXTURE_NORTH]);
        texture = &engine->textures[TEXTURE_NORTH];
        printf("\t\t\t POST %p\n", texture);
        return (true);
    }
    else
        return (error_print_critical("Texture not found."), false);
    printf("ME ESTAS DICIENDO QUE SALES POR AQUI?\n ");
    return (true);
}
