/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:44:25 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/27 16:58:37 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VECTOR_H
# define VECTOR_H

#include "dda.h"
#include "vector.h"

# define MAP_TEXTURE_NORTH 			'1'
# define MAP_TEXTURE_SOUTH 			'2'
# define MAP_TEXTURE_EAST 			'3'
# define MAP_TEXTURE_WEST 			'4'

//t_texture

t_texture choose_texture(t_dda_raycasting *dda_ray, t_vector *ray);

#endif