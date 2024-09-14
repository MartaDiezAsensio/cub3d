/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:58:10 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 21:01:02 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VECTOR_H
# define VECTOR_H

# include "types.h" 
# include "point.h"

typedef	struct s_vector
{
	double	x;
	double	y;
	double	modulus;
		
}	t_vector;


t_vector	vector_new_from_points(t_point a, t_point b, bool normalize);
t_vector	vector_new_from_values(double _x, double _y, bool normalize);
void		vector_calculate_modulus(t_vector *vector);
void		vector_normalize(t_vector	*vector);
t_vector	vector_rotate(t_vector vector, float rad_angle, bool normalize);
t_vector	vector_add(t_vector vector1, t_vector vector2, bool normalize);
t_point		vector_calculate_new_point(t_point origin, t_vector direction, double n_times);


#endif