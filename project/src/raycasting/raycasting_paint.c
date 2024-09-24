/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_paint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:15:21 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/24 21:41:13 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "vector.h"
#include "dda.h"
#include "tile.h"
#include "error.h"
#include "point.h"


#include <stdio.h>

//t_vector    raycasting_new_ray(int x, int w, t_camera camera);
//t_tile *dda_calculate_hit(t_point	origin, t_vector direction, t_map map);
//double	point_calculate_distance(t_point point1, t_point point2)

static int  raycasting_calculate_wall(double distance, int screen_height)
{
    int line_height;

//    line_height = (int) (((double)screen_height ) / distance);

//    line_height = (int) (screen_height * 405.0f/ distance);
    line_height = (int) (screen_height / distance);
 //   line_height = (distance  / 41) *screen_height;
   // printf("\t\tdistance %f pixels %d tamano pantalla %d \n", distance, line_height, screen_height);
    return (line_height);
    //return (screen_height / distance); 

}
/*
#include <math.h>

static double  get_cos_between_vectors(t_vector camera_dir, t_vector ray_dir)
{
    //https://www.geeksforgeeks.org/angle-between-two-vectors-formula/
    double cosinus;
    
    cosinus = (camera_dir.x * ray_dir.x + camera_dir.y * ray_dir.y)  / (camera_dir.modulus * ray_dir.modulus);
    return (cosinus);
}
*/

bool    raycasting_paint(t_engine *engine)
{

    // Para cada columna de pixels...
        // se genera ladda->dy direccion del rayo de la columna de pixels
        // se calcula el punto final para la dda con el punto origen  , la direccion del rayo , el multiplicador INT_MAX
        // aplicamos dda para encontrar la colision pansandole , el punto origen ,punto final y el mapa.
        // cuando tenemos la colision, calculamos la distancia con el punto origen.
        // calculamos el numero de pixeles de pared segun la distancia de colision ( en el futuro , calcularemos tb la textura N,X,W,E)
        // pintamos la columna de pixeles x con el techo, pared y suelo.
        // liberar recursos ( si fuera necesario)

    size_t		x;
    t_vector	ray_direction;
    t_dpoint		point_colition;
	double		    distance;
	int			    num_pixels_wall;
    t_orientations  orientation;
    int             side;
    double cosinus;

	x = 0;

    (void)point_colition;
    (void)orientation;
    (void)side;
    (void)cosinus;
//double	point_calculate_xdist(t_point point1, t_point point2)
    //printf("MAP HEIGHT %dWIDTH %d\n",engine->cfg->map);
	while(x < engine->screen.x)
	{
        //printf("Column %ld\n", x);
        
    	ray_direction = raycasting_new_ray(x, engine->screen.x, engine->camera); 
/*        
        if (!dda_calculate_hit(engine->camera.position, ray_direction, engine->cfg->map, &point_colition, &side))
		{
			printf("%s", "dda not working");
			return (false);
		}
*/        /*
        if (side == HIT_X_SIDE)
            distance = dpoint_calculate_xdist(engine->camera.position, point_colition);
        else
            distance = dpoint_calculate_ydist(engine->camera.position, point_colition);
        */
      //  distance = dpoint_calculate_distance(engine->camera.position,  point_colition);
        /*
        if (!vector_get_orientation(ray_direction, &orientation))
        {
            printf("%s", "Orientation not working\n");
            return(false);
        }
        
        printf("\tOrientation : %d\n", orientation);
        
        if (orientation == NORTH || orientation == SOUTH)
            distance = dpoint_calculate_ydist(engine->camera.position, point_colition);
        if (orientation == WEST || orientation == EAST)
            distance = dpoint_calculate_xdist(engine->camera.position, point_colition);
        
        if (side == HIT_X_SIDE)
            distance = dpoint_calculate_xdist(engine->camera.position, point_colition);
        else
            distance = dpoint_calculate_ydist(engine->camera.position, point_colition);
        */
//        distance = dpoint_calculate_distance(engine->camera.position,  point_colition);
//        double distanceY;
//        double distanceX;
        
//        distanceY = dpoint_calculate_ydist(engine->camera.position, point_colition);
//        distanceX = dpoint_calculate_xdist(engine->camera.position, point_colition);
        
//        printf(" \t\tColition side : %d point x %f , y %f  camera point x %f y %f\n", side, point_colition.x, point_colition.y, engine->camera.position.x, engine->camera.position.y);
//        if (distanceX  <= distanceY)
//            distance = distanceX;
//        else
//            distance = distanceY;
//        distance = dpoint_calculate_distance(engine->camera.position,  point_colition);
        //distance = 0.3f;
        
        if (!dda_calculate_hit_v2(engine->camera.position, ray_direction, engine->cfg->map, &side, &distance))
        {
            printf("%s", "dda not working");
			return (false);
        }

        //distance = distance * get_cos_between_vectors(engine->camera.direction, ray_direction);
        num_pixels_wall = raycasting_calculate_wall(distance, engine->screen.y);
        //printf("\t\t  %f\n", distance);
        engine_render_column(*engine, x, num_pixels_wall);
        //revisasr si hace falta liberar recursos.
        x++;
    }
    //printf("\n\n\n\nGabriel\n");
    return (true);
}