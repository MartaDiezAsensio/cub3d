/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:06:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/24 21:01:33 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"

t_vector	vector_new_from_points(t_point a, t_point b, bool normalize)
{
	t_vector	vector;

	vector.x = b.x - a.x;
	vector.y = b.y - a.y;
	if (normalize)
		vector_normalize(&vector);
	else
		vector_calculate_modulus(&vector);
	return (vector);
}

t_vector	vector_new_from_values(double _x, double _y, bool normalize)
{
	t_vector	vector;

	vector.x = _x;
	vector.y = _y;
	if (normalize)
		vector_normalize(&vector);
	else
		vector_calculate_modulus(&vector);
	return (vector);
}

void		vector_calculate_modulus(t_vector *vector)
{
	double	x_square;
	double	y_square;
	
	x_square = pow(vector->x, 2.0f);
	y_square = pow(vector->y, 2.0f);
	vector->modulus = sqrt(x_square + y_square);
}

void	vector_normalize(t_vector	*vector)
{
	vector_calculate_modulus(vector);
	vector->x = vector->x /  vector->modulus;
	vector->y = vector->y / vector->modulus;
	vector->modulus = 1.0f;
}
