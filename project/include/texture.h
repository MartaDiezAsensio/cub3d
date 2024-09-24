/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:48:04 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/24 20:47:40 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "MLX42/MLX42.h"

# define TEXTURE_NO_INIT_SIZE -1
typedef	struct s_texture 
{
	int				width;
	int				height;

	mlx_texture_t	*mlx_texture;
}	t_texture;

void	texture_init(t_texture *texture);
void	texture_destroy(t_texture *texture);

#endif