/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:48:04 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/07 22:43:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "MLX42/MLX42.h"
typedef	struct s_texture 
{
	int		width;
	int		height;
	char	*file_name;
	void	*mlx_image;
}	t_texture;

#endif