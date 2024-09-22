/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:29:22 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/22 13:49:43 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "point.h"
# include "vector.h"
# include "map.h"

typedef struct s_dda
{
	float	dx;
	float	dy;
	float	step;
	float	x;
	float	y;
	t_dpoint	final;
}	t_dda;

//bool	dda_calculate_hit(t_point	origin, t_vector direction, t_map map, t_dpoint *hit);
bool	dda_calculate_hit(t_dpoint	origin, t_vector direction, t_map map, t_dpoint *hit);

#endif