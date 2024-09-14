/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:35:14 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/20 22:00:14 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"

t_vector	vector_rotate(t_vector vector, float rad_angle, bool normalize)
{
	t_vector	result;

	result.x = vector.x * cos(rad_angle) - vector.y * sin(rad_angle);
	result.y = vector.x * sin(rad_angle) + vector.y * cos(rad_angle);	
	if (normalize)
		vector_normalize(&result);
	else
		vector_calculate_modulus(&result);
	return (result);
}

t_vector	vector_add(t_vector vector1, t_vector vector2, bool normalize)
{
	t_vector	result;

	result.x = vector1.x + vector2.x;
	result.y = vector1.y + vector2.y;
	if (normalize)
		vector_normalize(&result);
	else
		vector_calculate_modulus(&result);
	return (result); 
}

t_point		vector_calculate_new_point(t_point origin, t_vector direction, double n_times)
{
	t_point	new_point;

	new_point.x = origin.x + n_times * direction.x;
	new_point.y = origin.y + n_times * direction.y;
	return (new_point);
}