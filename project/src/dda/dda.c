/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:32:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/24 23:19:22 by gabriel          ###   ########.fr       */
=======
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:32:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/25 20:18:14 by mdiez-as         ###   ########.fr       */
>>>>>>> 7291751d225f7456b05386a565c5c659ee9f72e2
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <math.h>

#include "dda.h"
#include "error.h"

/*
	EN step ponemos el menor entre dx y dy para que en cada iteracion avancemos un paso en el x o y que tenga mayor diferencia.
	Es decir si x es la mayor, en cada iteracion avanzamos 1 en x  (dx/dx) y dy /dx en y. 
	Y viceversa.


	Ponemos 10000 para evitar un overfload en las coordenadas.
*/
static t_dda	dda_init(t_dpoint origin, t_vector direction)
{
	t_dda	dda_data;

	dda_data.x = origin.x;
	dda_data.y = origin.y;
	dda_data.final = dpoint_new(origin.x + direction.x * 1000.0f, origin.y + direction.y * 1000.0f);
<<<<<<< HEAD
=======
	/*
>>>>>>> 7291751d225f7456b05386a565c5c659ee9f72e2
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
/*
static	bool	dda_is_inside_map(t_dpoint point, t_map map)
{

	if (point.x < 0.0f || point.y < 0.0f)
		return (false);
<<<<<<< HEAD
=======
//	printf("\t\t\tmap width %zu map height %zu point x  %f point y %f \n", map.width, map.height, point.x, point.y);
>>>>>>> 7291751d225f7456b05386a565c5c659ee9f72e2
	if((int)point.x >= (int)map.width || (int)point.y >= (int)map.height)
		return(false);
	return (true);
}

static bool	dda_check_hit(t_dpoint point, t_map map)
{
<<<<<<< HEAD
	if ((map.map[(int)point.y][(int)point.x]) == MAP_TILE_WALL)
=======
//	printf("CHECK  HIT x f %f _ %d  CHECK HIT y f %f _ %d \n", point.x, (int)point.x, point.y, (int)point.y);
//	if ((map.map[(int)point.x][(int)point.y]) == MAP_TILE_WALL)
	if ((map.map[(int)point.y][(int)point.x]) == MAP_TILE_WALL)
//	if ((map.map[(int)(round(point.y))][(int)(round(point.x))]) == MAP_TILE_WALL)
>>>>>>> 7291751d225f7456b05386a565c5c659ee9f72e2
		return (true);
	return (false);
}
*/

//https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)
bool dda_calculate_hit(t_dpoint	origin, t_vector direction, t_map map, \
<<<<<<< HEAD
		t_dpoint *hit)
=======
		t_dpoint *hit, int *side)
>>>>>>> 7291751d225f7456b05386a565c5c659ee9f72e2
{
	t_dda		dda_data;
	int			i;
	t_dpoint	point;

<<<<<<< HEAD
=======
	//dda_data.final = dpoint_new(origin.x + direction.x * 100.0f, origin.y + direction.y * 100.0f);
>>>>>>> 7291751d225f7456b05386a565c5c659ee9f72e2
	dda_data = dda_init(origin, direction);
	i = 0;
	while(i <= (int)dda_data.step)
	{
<<<<<<< HEAD
		point = dpoint_new(dda_data.x, dda_data.y);
//		if (!dda_is_inside_map(point, map))
		if (!map_is_inside(map, point.x, point.y))
			return (error_print_critical("Ray does not find hit."), false);
//		if(dda_check_hit(point, map))
		if(map_is_wall(map, point.x, point.y))
=======

		point = dpoint_new(dda_data.x, dda_data.y);

		if (!dda_is_inside_map(point, map))
		{
			printf("FUERA DEL MAPA x %f y %f \n", point.x, point.y);
			return (false);
		}
		if(dda_check_hit(point, map))
>>>>>>> 7291751d225f7456b05386a565c5c659ee9f72e2
		{
			*hit = point;
			hit->x =  (int) point.x;
			hit->y = (int) point.y;
			return (true);
		}
		dda_next_step(&dda_data);
		i++;
	}
	return (error_print_critical("Ray does not find hit."), false);
}
