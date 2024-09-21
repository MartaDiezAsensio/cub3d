/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:06:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/21 19:37:00 by mdiez-as         ###   ########.fr       */
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

#include <stdio.h>
t_vector	vector_new_from_values(double _x, double _y, bool normalize)
{
	t_vector	vector;

	vector.x = _x;
	vector.y = _y;
//	printf("\tINIT %f %f\n", vector.x, vector.y);
	if (normalize)
		vector_normalize(&vector);
	else
		vector_calculate_modulus(&vector);
//	printf("\tPOST INIT %f %f\n", vector.x, vector.y);
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
