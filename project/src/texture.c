/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:53:10 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/27 16:26:16 by mdiez-as         ###   ########.fr       */
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
