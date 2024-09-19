/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render_column.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:55:05 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/19 20:52:56 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "MLX42/MLX42.h"

//color = create_color(0xAA, 0x00, 0x00);
bool	engine_render_column(t_engine engine, int x, unsigned int num_pixels_wall)
{
    int     screen_height;
    int     i;
    int     sky_limit;
    int     floor_limit;
    uint32_t    sky_color;
    uint32_t    floor_color;
    uint32_t    wall_color;

    screen_height = engine.screen.y;
    i = 0;
    sky_limit = engine.screen.middle_y - (num_pixels_wall / 2);
    floor_limit = engine.screen.middle_y + (num_pixels_wall / 2);

    sky_color = color_2_mlx(engine.cfg->ceiling_color);
    floor_color = color_2_mlx(engine.cfg->floor_color);
    wall_color = color_new_mlx(60, 60, 60);

    while (i <= sky_limit)
    {
        mlx_put_pixel(engine.img, x, i, sky_color);
        i++;
    }
    while (i <= floor_limit)
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
