/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:29:22 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/24 22:48:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "point.h"
# include "vector.h"
# include "map.h"

# define HIT_X_SIDE 0
# define HIT_Y_SIDE	1

typedef struct s_dda
{
	float	dx;
	float	dy;
	float	step;
	float	x;
	float	y;
	t_dpoint	final;
}	t_dda;


typedef struct s_dda_raycasting
{
	int			side;
	float		perpWallDist;
	t_point		map_point;
	int			stepX;
	int			stepY;
	float		sideDistX;
	float		sideDistY;
	float		deltaDistX;
	float		deltaDistY;
	
}	t_dda_raycasting;

bool	dda_calculate_hit(t_dpoint	origin, t_vector direction, t_map map, \
			t_dpoint *hit);
bool	dda_raycasting_calculate_hit(t_dpoint	origin, t_vector direction, \
			t_map map, t_dda_raycasting *dda_ray);

#endif