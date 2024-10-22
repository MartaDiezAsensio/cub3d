/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpoint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:41:24 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/02 16:28:06 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "point.h"

t_dpoint	dpoint_new(double x, double y)
{
	t_dpoint	point;

	point.x = x;
	point.y = y;
	return (point);
}

double	dpoint_calculate_distance(t_dpoint point1, t_dpoint point2)
{
	double distance;
	double	x;
	double	y;

	x = point2.x - point1.x;
	y = point2.y - point1.y;
	distance = sqrt(x*x + y*y);
	return (distance);
}

double	dpoint_calculate_xdist(t_dpoint point1, t_dpoint point2)
{
	double	distance;

	distance = point2.x - point1.x;
	return ((double)fabs(distance));
}

double	dpoint_calculate_ydist(t_dpoint point1, t_dpoint point2)
{
	double distance;

	distance = point2.y - point1.y;
	return ((double)fabs(distance));
}

float	dpoint_calculate_slope(t_dpoint p1, t_dpoint  p2)
{
	float slope;

	slope = ((float)(p2.y - p1.y)) / ((float)(p2.x - p1.x));
	return (slope);
}
