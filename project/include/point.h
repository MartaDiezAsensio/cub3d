/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:54:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/03 20:49:51 by gabriel          ###   ########.fr       */
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
float	point_calculate_slope(t_point point1, t_point  point2);

#endif