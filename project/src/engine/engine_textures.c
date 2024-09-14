/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:12:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/12 18:49:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "texture.h"
#include "engine.h"
//#include "mlx.h"
#include "MLX42/MLX42.h"
#include "libft.h"
#include "error.h"

//void	*mlx_png_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
bool	engine_texture_load(const char *filename, t_texture *texture, t_engine engine)
{
	char	*line;
/*	
	texture->mlx_image = mlx_xpm_file_to_image(engine.mlx, (char *)filename, \
		&texture->width, &texture->height);
	if (texture->mlx_image == NULL)
	{
		line = ft_strjoin(filename, " cannot be loaded.");
		if (line == NULL)
			return (error_perror_critical(),false);
		error_print_critical(line);
		free(line);
		return (false);
	}
*/

	(void)line;
	(void)filename;
	(void)texture;
	(void)engine;	
	return (true);
}

bool	engine_textures_load(t_engine *engine)
{
	t_config	*cfg;

	cfg = engine->cfg;
	if (!engine_texture_load(cfg->north_texture, &engine->textures[TEXTURE_NORTH], *engine))
		return (false);
	if (!engine_texture_load(cfg->south_texture, &engine->textures[TEXTURE_SOUTH], *engine))
		return (false);
	if (!engine_texture_load(cfg->west_texture, &engine->textures[TEXTURE_WEST], *engine))
		return (false);
	if (!engine_texture_load(cfg->east_texture, &engine->textures[TEXTURE_EAST], *engine))
		return (false);
	return (true);	
}

static void	engine_texture_destroy(t_engine *engine, t_texture *texture)
{
	/*
	mlx_destroy_image(engine->mlx, texture->mlx_image);
	texture->mlx_image = NULL;
	*/
	(void)engine;
	(void)texture;
	
}

void	engine_textures_destroy(t_engine *engine)
{
	engine_texture_destroy(engine, &engine->textures[TEXTURE_NORTH]);
	engine_texture_destroy(engine, &engine->textures[TEXTURE_SOUTH]);
	engine_texture_destroy(engine, &engine->textures[TEXTURE_WEST]);
	engine_texture_destroy(engine, &engine->textures[TEXTURE_EAST]);	
}