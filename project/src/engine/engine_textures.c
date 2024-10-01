/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:12:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/01 20:38:21 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "texture.h"
#include "engine.h"
#include "MLX42/MLX42.h"
#include "libft.h"
#include "error.h"
#include "texture.h"

#include <stdio.h>

bool	engine_texture_load(const char *filename, t_texture *texture)
{
	texture->mlx_texture = mlx_load_png(filename);
	if (texture->mlx_texture == NULL)
		return (error_print_mlx_perror(), false);
	texture->width = texture->mlx_texture->width;
	texture->height = texture->mlx_texture->height;
	return (true);
}

bool	engine_textures_load(t_engine *engine)
{
	printf("\t\t\t\t\tTEXTURAS LOAD\n");
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
