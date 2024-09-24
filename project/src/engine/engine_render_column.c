/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render_column.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:55:05 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/23 21:57:19 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "MLX42/MLX42.h"

#include <stdio.h>

//color = create_color(0xAA, 0x00, 0x00);
bool	engine_render_column(t_engine engine, int x, unsigned int num_pixels_wall)
{
    int     screen_height;
    int     i;
    int     sky_end;
    int     floor_start;
    uint32_t    sky_color;
    uint32_t    floor_color;
    uint32_t    wall_color;

    screen_height = engine.screen.y;
    i = 0;
    
    sky_end = engine.screen.middle_y - (num_pixels_wall / 2);
    if (sky_end < 0)
        sky_end = 0;
    floor_start = engine.screen.middle_y + (num_pixels_wall / 2);
    if ((size_t)floor_start >= engine.screen.y)
        floor_start =engine.screen.y - 1;
    sky_color = color_2_mlx(engine.cfg->ceiling_color);
    floor_color = color_2_mlx(engine.cfg->floor_color);
    wall_color = color_new_mlx(60, 60, 60);
    while (i <= sky_end)
    //while (i <= sky_limit)
    {
        mlx_put_pixel(engine.img, x, i, sky_color);
        i++;
    }
//  while (i <= floor_limit)
    while (i <= floor_start)
    {
        mlx_put_pixel(engine.img, x, i, wall_color);
        i++;
    }
    while (i < screen_height)
    {
        mlx_put_pixel(engine.img, x, i, floor_color);
        i++;
    }
    return (true);
}
