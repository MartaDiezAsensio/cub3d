/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:54:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/27 16:04:41 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_H
# define POINT_H

# include <stddef.h>

typedef	struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef	struct s_dpoint
{
	double		x;
	double		y;
}	t_dpoint;

//t_point
t_point	point_new(int x, int y);
double	point_calculate_distance(t_point point1, t_point point2);
double	point_calculate_xdist(t_point point1, t_point point2);
double	point_calculate_ydist(t_point point1, t_point point2);
float	point_calculate_slope(t_point point1, t_point  point2);

//t_dpoint
t_dpoint	dpoint_new(double x, double y);
double	dpoint_calculate_distance(t_dpoint point1, t_dpoint point2);
double	dpoint_calculate_xdist(t_dpoint point1, t_dpoint point2);
double	dpoint_calculate_ydist(t_dpoint point1, t_dpoint point2);
float	dpoint_calculate_slope(t_dpoint point1, t_dpoint  point2);

#endif
