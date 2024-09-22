/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:54:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/22 10:33:54 by greus-ro         ###   ########.fr       */
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


t_point	point_new(int x, int y);
double	point_calculate_distance(t_point point1, t_point point2);
double	point_calculate_xdist(t_point point1, t_point point2);
double	point_calculate_ydist(t_point point1, t_point point2);
float	point_calculate_slope(t_point point1, t_point  point2);


#endif