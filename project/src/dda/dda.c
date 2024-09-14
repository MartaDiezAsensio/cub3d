/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:32:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/05 18:46:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <math.h>

#include "dda.h"


/*
	EN step ponemos el menor entre dx y dy para que en cada iteracion avancemos un paso en el x o y que tenga mayor diferencia.
	Es decir si x es la mayor, en cada iteracion avanzamos 1 en x  (dx/dx) y dy /dx en y. 
	Y viceversa
*/
static t_dda	dda_init(t_point origin, t_vector direction)
{
	t_dda	dda_data;

	dda_data.x = origin.x;
	dda_data.y = origin.y;
	dda_data.final = point_new(origin.x + direction.x * INT_MAX, origin.y + direction.y * INT_MAX);
	dda_data.dx = dda_data.final.x - dda_data.x;
	dda_data.dy = dda_data.final.y - dda_data.y;
	if (fabs(dda_data.dx) >= fabs(dda_data.dy))
		dda_data.step = fabs(dda_data.dx);
	else
		dda_data.step = fabs(dda_data.dy);
	dda_data.dx = dda_data.dx / dda_data.step;
	dda_data.dy = dda_data.dy / dda_data.step;
	return (dda_data);
}

static	void	dda_next_step(t_dda *dda)
{
	dda->x = dda->x + dda->dx;
	dda->y = dda->y + dda->dy;
}

static	bool	dda_is_inside_map(t_point point, t_map map)
{

	(void)point;
	(void)map;
	return (true);
}

static t_tile *dda_check_hit(t_point point, t_map map)
{
	(void)point;
	(void)map;
	return (NULL);
}

//https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)

t_tile *dda_calculate_hit(t_point	origin, t_vector direction, t_map map)
{
	t_dda	dda_data;
	int		i;
	t_point	point;
	t_tile	*tile;

	dda_data.final = point_new(origin.x + direction.x * INT_MAX, origin.y + direction.y * INT_MAX);
	dda_data = dda_init(origin, direction);
	i = 0;
	while( i <= dda_data.step)
	{
		point = point_new(round(dda_data.x), round(dda_data.y));
		if (!dda_is_inside_map(point, map))
			return (NULL);
		tile = dda_check_hit(point, map);
		if (tile != NULL)
			return (tile);
		dda_next_step(&dda_data);
		i++;
	}
	return (NULL);
}