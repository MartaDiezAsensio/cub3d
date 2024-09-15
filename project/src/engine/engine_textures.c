/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:12:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/15 13:57:41 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "texture.h"
#include "engine.h"
//#include "mlx.h"
#include "MLX42/MLX42.h"
#include "libft.h"
#include "error.h"
#include "texture.h"

//void	*mlx_png_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
bool	engine_texture_load(const char *filename, t_texture *texture)
{
	//mlx_texture_t* mlx_load_png(const char* path);
	texture->mlx_texture = mlx_load_png(filename);
	if (texture->mlx_texture == NULL)
		return (error_print_mlx_perror(), false);
	texture->width = texture->mlx_texture->width;
	texture->height = texture->mlx_texture->height;
	return (true);
}

bool	engine_textures_load(t_engine *engine)
{
	t_config	*cfg;

	cfg = engine->cfg;
	if (!engine_texture_load(cfg->north_texture, &engine->textures[TEXTURE_NORTH]))
		return (false);
	if (!engine_texture_load(cfg->south_texture, &engine->textures[TEXTURE_SOUTH]))
		return (false);
	if (!engine_texture_load(cfg->west_texture, &engine->textures[TEXTURE_WEST]))
		return (false);
	if (!engine_texture_load(cfg->east_texture, &engine->textures[TEXTURE_EAST]))
		return (false);
	return (true);	
}

void	engine_textures_destroy(t_engine *engine)
{
	texture_destroy(&engine->textures[TEXTURE_NORTH]);
	texture_destroy(&engine->textures[TEXTURE_SOUTH]);
	texture_destroy(&engine->textures[TEXTURE_WEST]);
	texture_destroy(&engine->textures[TEXTURE_EAST]);
}