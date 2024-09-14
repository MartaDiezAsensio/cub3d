/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:41:24 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/03 20:53:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "point.h"

t_point	point_new(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

double	point_calculate_distance(t_point point1, t_point point2)
{
	double distance;
	double	x;
	double	y;

	x = point2.x - point1.x;
	y = point2.y - point1.y;
	distance = sqrt(x*x + y*y);
	return (distance);
}

float	point_calculate_slope(t_point p1, t_point  p2)
{
	float slope;

	slope = ((float)(p2.y - p1.y)) / ((float)(p2.x - p1.x));
	return (slope);
}