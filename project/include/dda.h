/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:29:22 by gabriel           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/26 16:22:51 by mdiez-as         ###   ########.fr       */
=======
/*   Updated: 2024/09/25 20:18:34 by mdiez-as         ###   ########.fr       */
>>>>>>> 7291751d225f7456b05386a565c5c659ee9f72e2
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

<<<<<<< HEAD
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
=======
//bool	dda_calculate_hit(t_point	origin, t_vector direction, t_map map, t_dpoint *hit);
bool	dda_calculate_hit(t_dpoint	origin, t_vector direction, t_map map, t_dpoint *hit, int *side);
bool	dda_calculate_hit_v2(t_dpoint	origin, t_vector direction, t_map map, int *side, double *perpWallDist);
>>>>>>> 7291751d225f7456b05386a565c5c659ee9f72e2

bool	dda_calculate_hit(t_dpoint	origin, t_vector direction, t_map map, \
			t_dpoint *hit);
bool	dda_raycasting_calculate_hit(t_dpoint	origin, t_vector direction, \
			t_map map, t_dda_raycasting *dda_ray);
#endif
