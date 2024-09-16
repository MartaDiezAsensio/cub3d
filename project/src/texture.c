/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:53:10 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/15 14:15:01 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

#include <stdio.h>

void	texture_init(t_texture *texture)
{
	texture->mlx_texture = NULL;
	texture->height = TEXTURE_NO_INIT_SIZE;
	texture->width = TEXTURE_NO_INIT_SIZE;
}

void	texture_destroy(t_texture *texture)
{
	if (texture->mlx_texture != NULL)
	{
		mlx_delete_texture(texture->mlx_texture);
		texture->mlx_texture = NULL;
	}
	texture->height = TEXTURE_NO_INIT_SIZE;
	texture->width = TEXTURE_NO_INIT_SIZE;
	
}