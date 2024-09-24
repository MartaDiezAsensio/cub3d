/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:32:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/24 02:11:39 by greus-ro         ###   ########.fr       */
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
static t_dda	dda_init(t_dpoint origin, t_vector direction)
{
	t_dda	dda_data;

	dda_data.x = origin.x;
	dda_data.y = origin.y;
	dda_data.final = dpoint_new(origin.x + direction.x * 1000.0f, origin.y + direction.y * 1000.0f);
	/*
	dda_data.dx = dda_data.final.x - dda_data.x;
	dda_data.dy = dda_data.final.y - dda_data.y;
	if (fabs(dda_data.dx) >= fabs(dda_data.dy))
		dda_data.step = fabs(dda_data.dx);
	else
		dda_data.step = fabs(dda_data.dy);
	dda_data.dx = dda_data.dx / dda_data.step;
	dda_data.dy = dda_data.dy / dda_data.step;
	*/
	dda_data.dx = direction.x;
	dda_data.dy = direction.y;
//	printf("origin.x %f origin.y %f dda->dx %f dda->dy %f step = %f \n",origin.x,origin.y,dda_data.dx, dda_data.dy, dda_data.step);
	return (dda_data);
}

static	void	dda_next_step(t_dda *dda, int *side)
{
	/*
	int x;
	int y;

	x = dda->x;
	y = dda->y;
	*/
	dda->x = dda->x + dda->dx;
	dda->y = dda->y + dda->dy;
	/*
	printf("\t\t\tdda dx = %f dy = %f x %d y %d nx %f ny %f round x %d round y %d\n", dda->dx, dda->dy,x,y, dda->x, dda->y,(int)dda->x,(int)dda->y);
	if (fabs(dda->dy) == 1.0f)
	{
		//if (x != dda->x)
		if (x != (int)dda->x)
			*side = HIT_X_SIDE;
		else
			*side = HIT_Y_SIDE;
	}
	if (fabs(dda->dx) == 1.0f)
	{
		//if (y != (int)dda->y)
		if (y != (int)dda->y)
			*side = HIT_Y_SIDE;
		else
			*side = HIT_X_SIDE;
	}
	*/
	*side = 0;
}

static	bool	dda_is_inside_map(t_dpoint point, t_map map)
{

	if (point.x < 0.0f || point.y < 0.0f)
		return (false);
//	printf("\t\t\tmap width %zu map height %zu point x  %f point y %f \n", map.width, map.height, point.x, point.y);
	if((int)point.x >= (int)map.width || (int)point.y >= (int)map.height)
		return(false);
	return (true);
}

/*static t_tile *dda_check_hit(t_point point, t_map map)
{
	if ((map.map[point.x][point.y]) == MAP_TILE_WALL)
	return (NULL);
}*/

static bool	dda_check_hit(t_dpoint point, t_map map)
{
//	printf("CHECK  HIT x f %f _ %d  CHECK HIT y f %f _ %d \n", point.x, (int)point.x, point.y, (int)point.y);
//	if ((map.map[(int)point.x][(int)point.y]) == MAP_TILE_WALL)
	if ((map.map[(int)point.y][(int)point.x]) == MAP_TILE_WALL)
//	if ((map.map[(int)(round(point.y))][(int)(round(point.x))]) == MAP_TILE_WALL)
		return (true);
	return (false);
}

//https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)

//t_tile *dda_calculate_hit(t_point	origin, t_vector direction, t_map map)
bool dda_calculate_hit(t_dpoint	origin, t_vector direction, t_map map, \
		t_dpoint *hit, int *side)
{
	t_dda	dda_data;
	int		i;
	t_dpoint	point;

	//dda_data.final = dpoint_new(origin.x + direction.x * 100.0f, origin.y + direction.y * 100.0f);
	dda_data = dda_init(origin, direction);
//	printf("dda.x %f dda.y %f step  %f \n",dda_data.dx, dda_data.dy, dda_data.step);
	i = 0;
	//while(i <= (int)dda_data.step)
	while(true)
	{

		point = dpoint_new(dda_data.x, dda_data.y);

		if (!dda_is_inside_map(point, map))
		{
			printf("FUERA DEL MAPA x %f y %f \n", point.x, point.y);
			return (false);
		}
		if(dda_check_hit(point, map))
		{
			*hit = point;
			//hit->x =  (int) point.x;
			//hit->y = (int) point.y;
			//*hit = dpoint_new(origin.x + direction.x * (float)i, origin.y + direction.y * (float)i);
			/*
			if (*side == HIT_X_SIDE)
			{
				hit->x = point.x;
				hit->y = (int)point.y;
			}
			else
			{
				hit->x = (int)point.x;
				hit->y = point.y;
			}*/
			double t1;
			double t2;
			t1 = (point.x - origin.x) / direction.x;
			t2 = (point.y - origin.y) / direction.y;
			if (t1 < t2)
				*side = HIT_X_SIDE;
			else
				*side = HIT_Y_SIDE;
			printf("\tHIT! X %f Y %f SIDE: %d Origi x %f y %f\n",hit->x, hit->y,*side, origin.x, origin.y);
			return (true);
		}
		dda_next_step(&dda_data, side);
		i++;
	}
//	printf("SALE!!\n");
	return (false);
}
