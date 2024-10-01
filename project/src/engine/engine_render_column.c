/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render_column.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:55:05 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/01 19:13:12 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "MLX42/MLX42.h"

#include <stdio.h>

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
    //Primero calculamos que textura utilizar. (Funcion de Marta de  choose_texture).
        //t_texture choose_texture(t_dda_raycasting *dda_ray, t_vector *ray);
    //Calculamos el punto exacto de interseccion  con el rayo (SOLO la coordenada X).
        /*
        double wallX; //where exactly the wall was hit
        if (side == 0) wallX = posY + perpWallDist * rayDirY;
        else           wallX = posX + perpWallDist * rayDirX;
        wallX -= floor((wallX));
        */
    //Con la parte decimal de la coordenada X del punto de interseccion X, calcula la coordenada X (columna de la textura ) que hay que pintar.
        // Para obtener la coordenada X , multiplica el ancho de la textura (width) por el % (wallX) obtenido del punto anterior.
        /*
        int texX = int(wallX * double(texWidth));
        if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
        if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;
        */
    //Aqui empezamos el escalado de la textura.
        // How much to increase the texture coordinate per screen pixel
        //Obtiene  cuantos pixles de textura tenemos que avanzar (step) cada vez que pintamos un pixel de pantalla
            //double step = 1.0 * texHeight / lineHeight;
        //Obtenemos el punto de inicio (para pintar) dentro de la textura
            //double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
        //Pintamos los pixeles de pared ( desde sky_end hasta  floor_start)
            //for(int y = drawStart; y<drawEnd; y++)
            //{
                // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
                // Obtiene la posicion Y de la tetura PERO vigila que  el valor obtenido NO SEA MAYOR que la propia altura de la textura. (overflow)
                //int texY = (int)texPos & (texHeight - 1);
                //Avanzamos step pixels en la textura
                //texPos += step;
                //Aqui obtiene el color de la textura que ha de pintar... 
                //Uint32 color = texture[texNum][texHeight * texY + texX];
                //OPCIONAL:
                    //Oscurece las texturas que han chocado con Y ( imagino que para dar mas sensacion de profundidad.)
                    //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
                    //if(side == 1) color = (color >> 1) & 8355711;
                //Pintamos el pixel.
                //buffer[y][x] = color;
            //}
    

    
    //Modo plano...
    /*
    wall_color = color_new_mlx(60, 60, 60);
    while (i <= sky_end)
    {
        mlx_put_pixel(engine.img, x, i, sky_color);
        i++;
    }
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
    */


    return (true);
}
