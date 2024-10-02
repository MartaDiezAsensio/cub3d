/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_orientation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:27:15 by greus-ro          #+#    #+#             */
/*   Updated: 2024/10/02 20:47:48 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "error.h"

/*
tan(x).
			SLOPE				|		ANGLE				|	ORIENTATION
	from	0		to	1		=>	from	0	to	45				E
	from	1		to	inf		=>	from	45	to	90				N	OK
	from	-inf    to	-1		=>	from	90	to	135				N
	from	-1      to	0		=>	from	135	to	180				W
	from	0       to	1		=>	from	180	to	225				W
	from	1		to	inf		=>	from	225	to	270				S	OK
	from	-inf	to	-1		=>	from	270	to	315				S
	from	-1		to	0		=>	from	315	to	0				E

See "Chuleta" => 
https://rodrigoanchorena.wixsite.com/aprendematematica/en-blanco-cnay 
	or 
/docs/tan.jpg

When we have x = 0 and y positive, it is 90 degrees
When we have x = 0 and y negative, it is 270 degrees

*/

static bool	vector_slope_treat_inf(t_vector vector, \
			t_orientations *orientation)
{
	if (vector.y >= 0.0f)
		*orientation = SOUTH;
	else
		*orientation = NORTH;
	return (true);
}

/*
	from	-inf    to	-1		=>	from	90	to	135				N	y >= 0
	from	-inf	to	-1		=>	from	270	to	315				S	y <  0
	from	-1      to	0		=>	from	135	to	180				W	x <  0
	from	-1		to	0		=>	from	315	to	0				E	x >= 0
*/
static bool	vector_slope_treat_negative(double slope, t_vector vector, \
			t_orientations *orientation)
{
	if (slope >= -1.0f)
	{
		if (vector.x < 0.0f)
			*orientation = WEST;
		else
			*orientation = EAST;
		return (true);
	}
	else
	{
		if (vector.y < 0.0f)
			*orientation = NORTH;
		else
			*orientation = SOUTH;
		return (true);
	}
}

/*
	from	0		to	1		=>	from	0	to	45				E	x >= 0
	from	0       to	1		=>	from	180	to	225				W	x <  0
	from	1		to	inf		=>	from	225	to	270				S	y <  0
	from	1		to	inf		=>	from	45	to	90				N	y >= 0
*/
static bool	vector_slope_treat_positive(double slope, t_vector vector, \
			t_orientations *orientation)
{
	if (slope <= 1.0f)
	{
		if (vector.x >= 0.0f)
			*orientation = EAST;
		else
			*orientation = WEST;
		return (true);
	}
	else
	{
		if (vector.y < 0.0f)
			*orientation = NORTH;
		else
			*orientation = SOUTH;
		return (true);
	}
}

bool	vector_get_orientation(t_vector vector, \
			t_orientations *orientation)
{
	double	slope;

	if (vector.x == 0.0f && vector.y == 0.0f)
		return (error_print_critical("Found a vector with x=0, y=0"), false);
	if (vector.x >= 0.0f && vector.x <= EPSILON)
		return (vector_slope_treat_inf(vector, orientation));
	slope = vector.y / vector.x;
	if (slope >= 0.0f)
		return (vector_slope_treat_positive(slope, vector, orientation));
	else
		return (vector_slope_treat_negative(slope, vector, orientation));
	return (false);
}
