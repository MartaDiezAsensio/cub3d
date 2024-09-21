/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:32:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/21 20:29:29 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <math.h>

#include "dda.h"

#include <stdio.h>

/*
	EN step ponemos el menor entre dx y dy para que en cada iteracion avancemos un paso en el x o y que tenga mayor diferencia.
	Es decir si x es la mayor, en cada iteracion avanzamos 1 en x  (dx/dx) y dy /dx en y. 
	Y viceversa.


	Ponemos 10000 para evitar un overfload en las coordenadas.
*/
static t_dda	dda_init(t_point origin, t_vector direction)
{
	t_dda	dda_data;

	dda_data.x = origin.x;
	dda_data.y = origin.y;
	dda_data.final = point_new(origin.x + direction.x * 10000, origin.y + direction.y * 10000);
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

	if(point.x < 0 || point.y < 0)
		return (false);
	//printf("\t\t\tmap width %zu map height %zu \n", map.width, map.height);
	if(point.x >= (int)map.width || point.y >= (int)map.height)
		return(false);
	return (true);
}

/*static t_tile *dda_check_hit(t_point point, t_map map)
{
	if ((map.map[point.x][point.y]) == MAP_TILE_WALL)
	return (NULL);
}*/

static bool	dda_check_hit(t_point point, t_map map)
{
	if ((map.map[point.x][point.y]) == MAP_TILE_WALL)
		return (true);
	return (false);
}

//https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)

//t_tile *dda_calculate_hit(t_point	origin, t_vector direction, t_map map)
bool dda_calculate_hit(t_point	origin, t_vector direction, t_map map, \
		t_point *hit)
{
	t_dda	dda_data;
	int		i;
	t_point	point;

	dda_data.final = point_new(origin.x + direction.x * 10000, origin.y + direction.y * 10000);
	dda_data = dda_init(origin, direction);
	i = 0;
	while( i <= dda_data.step)
	{
		point = point_new(round(dda_data.x), round(dda_data.y));
		if (!dda_is_inside_map(point, map))
		{
			//printf("FUERA DEL MAPA x %d y %d \n", point.x, point.y);
			return (false);
		}
		if(dda_check_hit(point, map))
		{
			//printf("El hit esta en: x%d y %d\n", point.x, point.y);
			*hit = point;
			return (true);
		}
		dda_next_step(&dda_data);
		i++;
	}
	//printf("SALE!!\n");
	return (false);
}