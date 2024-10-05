/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render_column_wall.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:55:05 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/05 23:42:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "engine.h"
#include "MLX42/MLX42.h"
#include "texture.h"
#include "color.h"
#include "render.h"

/*	
	//Primero calculamos que textura utilizar. (Funcion de Marta de 
			choose_texture).
		//t_texture choose_texture(t_dda_raycasting *dda_ray, t_vector *ray);
	//Calculamos el punto exacto de interseccion  con el rayo 
			(SOLO la coordenada X).
		
		double wallX; //where exactly the wall was hit
		if (side == 0) wallX = posY + perpWallDist * rayDirY;
		else           wallX = posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));
		
	//Con la parte decimal de la coordenada X del punto de interseccion X, 
	calcula la coordenada X (columna de la textura ) que hay que pintar.
		// Para obtener la coordenada X , multiplica el ancho de la textura 
			(width) por el % (wallX) obtenido del punto anterior.
		
		int texX = int(wallX * double(texWidth));
		if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
		if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;
		
	//Aqui empezamos el escalado de la textura.
		// How much to increase the texture coordinate per screen pixel
		//Obtiene cuantos pixles de textura tenemos que avanzar (step) 
			cada vez que pintamos un pixel de pared en la pantalla
			//double step = 1.0 * texHeight / lineHeight;
		//Obtenemos el punto de inicio (para pintar) dentro de la textura
			//double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
		//Pintamos los pixeles de pared ( desde sky_end hasta  floor_start)
			//for(int y = drawStart; y<drawEnd; y++)
			//{
				// Cast the texture coordinate to integer, and mask with 
					(texHeight - 1) in case of overflow
				// Obtiene la posicion Y de la tetura PERO vigila que  el 
					valor obtenido NO SEA MAYOR que la propia altura de la 
					textura. (overflow)
				//int texY = (int)texPos & (texHeight - 1);
				//Avanzamos step pixels en la textura
				//texPos += step;
				//Aqui obtiene el color de la textura que ha de pintar... 
				//Uint32 color = texture[texNum][texHeight * texY + texX];
				//OPCIONAL:
					//Oscurece las texturas que han chocado con Y (imagino que
						 para dar mas sensacion de profundidad.)
					//make color darker for y-sides: R, G and B byte each 
						divided through two with a "shift" and an "and"
					//if(side == 1) color = (color >> 1) & 8355711;
				//Pintamos el pixel.
				//buffer[y][x] = color;
			//}
*/

static uint32_t	get_pixel_of_wall(double *tex_pos, t_texture texture, \
					double step, int tex_x)
{
	uint32_t	wall_color;
	int			tex_y;
	int			row_texture;

	tex_y = ((int)(*tex_pos)) & (texture.height - 1);
	(*tex_pos) += step;
	row_texture = texture.width * tex_y + tex_x;
	wall_color = color_new_mlx(texture.mlx_texture->pixels[row_texture * 4], \
					texture.mlx_texture->pixels[row_texture * 4 + 1], \
					texture.mlx_texture->pixels[row_texture * 4 + 2]);
	return (wall_color);
}

//	if (dda.side == 0 && dda.ray.x > 0)
//		tex_x = texture.width - tex_x - 1;
//	if (dda.side == 1 && dda.ray.y < 0)
//		tex_x = texture.width - tex_x - 1;
static	int	get_point_of_wall(t_texture texture, t_dda_raycasting dda)
{
	int		tex_x;
	double	intersection;

	if (dda.side == 0)
		intersection = dda.origin.y + dda.perp_wall_dist * dda.ray.y;
	else
		intersection = dda.origin.x + dda.perp_wall_dist * dda.ray.x;
	intersection -= floor(intersection);
	tex_x = intersection * ((double)texture.width);
	return (tex_x);
}

bool	engine_render_paint_wall(t_engine engine, t_render_column render_col, \
				t_dda_raycasting dda)
{
	t_texture	texture;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			j;

	if (!choose_texture(&engine, &dda, &texture))
		return (false);
	step = 1.0 * texture.height / render_col.wall_size;
	tex_x = get_point_of_wall(texture, dda);
	tex_pos = (render_col.ceiling_end - engine.screen.middle_y + \
				render_col.wall_size / 2) * step;
	j = render_col.ceiling_end;
	while (j < render_col.floor_start)
	{
		mlx_put_pixel(engine.img, render_col.column, \
			j, get_pixel_of_wall(&tex_pos, texture, \
											step, tex_x));
		j++;
	}
	return (true);
}

/*
bool engine_gabriel(t_engine engine, t_dda_raycasting dda, int sky_end, 
		int floor_start, int screen_height, 
		unsigned int num_pixels_wall, int i, int x)
{
	t_texture   texture;
	//double		intersection;
	int 		texX;
	//int			texY;
	double		step;
	double		texPos;
	//int			row_texture;

	uint32_t    wall_color;
	
	if (!choose_texture(&engine, &dda , &texture))
		return (false);
	(void)screen_height;

	texX = get_point_of_wall(texture, dda);
	//ES curioso pero si le quitamos el if y le dejamos el texX 
	//por defecto, parece que funciona igual.
//	if (dda.side == 0 && dda.ray.x > 0.0f)
//		texX = texture.width - texX - 1;
//	if (dda.side == 1 && dda.ray.y < 0.0f)
//		texX = texture.width - texX - 1;
	step = 1.0 * texture.height / num_pixels_wall;
	//texPos = (sky_end - screen_height / 2 + num_pixels_wall / 2) * step;
	texPos = (sky_end - engine.screen.middle_y + num_pixels_wall / 2) * step;
	while (i <= floor_start)
	{
		
		wall_color = get_pixel_of_wall(&texPos, texture, step, texX);
		//Añadido para el oscurecido del color....
		//if(dda.side == 1) wall_color = (wall_color >> 1) & 8355711;
//		if(dda.side == 1) wall_color = (wall_color >> 1) & 0xFFFFFFFF;
		//FIn añadido
		mlx_put_pixel(engine.img, x, i, wall_color);
		i++;
	}
	return (true);
}
*/
