/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_v2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:32:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/24 01:28:23 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <math.h>

#include "dda.h"

#include <stdio.h>

/*
static	bool	dda_is_inside_map_v2(t_dpoint point, t_map map)
{

	if (point.x < 0.0f || point.y < 0.0f)
		return (false);
	if((int)point.x >= (int)map.width || (int)point.y >= (int)map.height)
		return(false);
	return (true);
}
*/

static bool	dda_check_hit_v2(t_dpoint point, t_map map)
{
	if ((map.map[(int)point.y][(int)point.x]) == MAP_TILE_WALL)
		return (true);
	return (false);
}

//https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)

//t_tile *dda_calculate_hit(t_point	origin, t_vector direction, t_map map)
bool dda_calculate_hit_v2(t_dpoint	origin, t_vector direction, t_map map, int *side, double *perpWallDist)
{
	
	t_dpoint	point;
	//which box of the map we're in
    int mapX = (int)origin.x;
    int mapY = (int)origin.y;

    //length of ray from current position to next x or y-side
	//Longitud total acumulada.
    double sideDistX;
    double sideDistY;

       //length of ray from one x or y-side to next x or y-side
	   //Es lo que cuesta saltar a la siguiente caqsilla de X o Y.
    double deltaDistX = (direction.x == 0.0f) ? 1e30 : fabs(1.0f / direction.x);
    double deltaDistY = (direction.y == 0.0f) ? 1e30 : fabs(1.0f / direction.y);
    //double perpWallDist;

    //what direction to step in x or y-direction (either +1 or -1)
    int stepX;
    int stepY;

    int hit = 0; //was there a wall hit?
    //int side; //was a NS or a EW wall hit?

/*
  sideDistX and sideDistY are initially the distance the ray has to travel from its start position to 
    the first x-side and the first y-side. Later in the code they will be incremented while steps are taken.
*/
      //calculate step and initial sideDist
      if (direction.x < 0.0f)
      {
        stepX = -1;
        //Obtenemos la parte decimal y la multiplicamos por el coste de saltar al siguiente punto x
        sideDistX = (origin.x - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0f - origin.x) * deltaDistX;
      }
 
      if (direction.y < 0.0f)
      {
        stepY = -1;
        sideDistY = (origin.y - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0f - origin.y) * deltaDistY;
      }

      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        //Saltamos al siguiente pixel por lo que a la distancia le sumamos el coste de saltar al siguiente pixel
        //segun hayamos saltado en x o y.
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          *side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          *side = 1;
        }
        //Check if ray has hit a wall
        //if (worldMap[mapX][mapY] > 0) hit = 1;
		point = dpoint_new(mapX, mapY);
		if (dda_check_hit_v2(point, map))
			hit = 1;
      } 
	if(*side == 0) 	*perpWallDist = (sideDistX - deltaDistX);
    	else        *perpWallDist = (sideDistY - deltaDistY);
	
/*
	printf("\t\tdistancia: direction x %f y %f\n",direction.x, direction.y);
	if(*side == 0) 	
		*perpWallDist = (mapX - origin.x + ( 1 - stepX) / 2) / direction.x;
//		*perpWallDist = ((mapX - (int)origin.x + ( 1 - stepX ) / 2) * deltaDistX);
    else
		*perpWallDist = (mapY - origin.y + ( 1 - stepY) / 2) / direction.y;
//		*perpWallDist = ((mapY - (int)origin.y + ( 1 - stepY ) / 2) * deltaDistY);
*/	
	return (true);
}