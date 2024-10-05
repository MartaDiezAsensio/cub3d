/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:48:04 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/05 23:15:02 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "MLX42/MLX42.h"
# include "dda.h"

typedef struct s_engine	t_engine;

# define TEXTURE_NO_INIT_SIZE -1

typedef struct s_texture
{
	int				width;
	int				height;
	mlx_texture_t	*mlx_texture;
}	t_texture;

void	texture_init(t_texture *texture);
void	texture_destroy(t_texture *texture);
bool	choose_texture(t_engine *engine, t_dda_raycasting *dda_ray, \
			t_texture *texture);

#endif
