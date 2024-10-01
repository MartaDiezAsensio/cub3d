/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render_column.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:55:05 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/01 23:17:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "MLX42/MLX42.h"

#include <stdio.h>
#include <math.h>
#include "textures.h"
#include "color.h"

#include <stdio.h>

bool	engine_render_column(t_engine engine, int x, unsigned int num_pixels_wall, t_dda_raycasting dda)
{
	int     screen_height;
	int     i;
	int     sky_end;
	int     floor_start;
	uint32_t    sky_color;
	uint32_t    floor_color;
	uint32_t    wall_color;

	screen_height = engine.screen.y;	
	sky_end = engine.screen.middle_y - (num_pixels_wall / 2);
	if (sky_end < 0)
		sky_end = 0;
	floor_start = engine.screen.middle_y + (num_pixels_wall / 2);
	if ((size_t)floor_start >= engine.screen.y)
		floor_start =engine.screen.y - 1;
	sky_color = color_2_mlx(engine.cfg->ceiling_color);
	floor_color = color_2_mlx(engine.cfg->floor_color);
	i = 0;
	

	
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
		//Obtiene  cuantos pixles de textura tenemos que avanzar (step) cada vez que pintamos un pixel de pared en la pantalla
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
	while (i <= sky_end)
	{
		mlx_put_pixel(engine.img, x, i, sky_color);
		i++;
	}

	t_texture   texture;
	double		interseccionX;
	int 		texX;
	int			texY;
	double		step;
	double		texPos;
	int			row_texture;
	
	if (!choose_texture(&engine, &dda , &texture))
		return (false);
	if (dda.side == 0)
		interseccionX = dda.origin.y + dda.perpWallDist * dda.ray.y;
	else
		interseccionX = dda.origin.x + dda.perpWallDist * dda.ray.x;
	interseccionX -= floor(interseccionX);
	texX = interseccionX * ((double)texture.width);
	if (dda.side == 0 && dda.ray.x > 0.0f)
		texX = texture.width - texX - 1;
	if (dda.side == 0 && dda.ray.y < 0.0f)
		texX = texture.width - texX - 1;
	step = 1.0 * texture.height / num_pixels_wall;
	texPos = (sky_end - screen_height / 2 + num_pixels_wall / 2) * step;
	while (i <= floor_start)
	{

		texY = (int)texPos & (texture.height - 1);
		texPos += step;
		row_texture = texture.height * texY + texX;
		wall_color = color_new_mlx(texture.mlx_texture->pixels[row_texture*4],texture.mlx_texture->pixels[row_texture*4 + 1],texture.mlx_texture->pixels[row_texture*4 + 2]);
		//Añadido para el oscurecido del color....
		//if(dda.side == 1) wall_color = (wall_color >> 1) & 8355711;
//		if(dda.side == 1) wall_color = (wall_color >> 1) & 0xFFFFFFFF;
		//FIn añadido
		mlx_put_pixel(engine.img, x, i, wall_color);
		i++;
	}
	while (i < screen_height)
	{
		mlx_put_pixel(engine.img, x, i, floor_color);
		i++;
	}
	//Modo plano...
/*	
	(void)dda;
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
