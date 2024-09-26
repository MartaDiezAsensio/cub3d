/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_paint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:15:21 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/26 16:30:04 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "raycasting.h"
#include "vector.h"
#include "dda.h"
#include "error.h"

static int  raycasting_calculate_wall(double distance, int screen_height)
{
	int line_height;
    int line_height;

    line_height = screen_height / distance;
//    line_height = (int) (((double)screen_height ) / distance);

//    line_height = (int) (screen_height * 405.0f/ distance);
    line_height = (int) (screen_height / distance);
 //   line_height = (distance  / 41) *screen_height;
   // printf("\t\tdistance %f pixels %d tamano pantalla %d \n", distance, line_height, screen_height);
    return (line_height);
    //return (screen_height / distance); 

	line_height = (int) (screen_height / distance);
	return (line_height);
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
	size_t				x;
	t_vector			ray_direction;
	int					num_pixels_wall;
	t_dda_raycasting	dda;

	x = 0;
	while(x < engine->screen.x)
	{
		ray_direction = raycasting_new_ray(x, engine->screen.x, engine->camera); 		
		if (!dda_raycasting_calculate_hit(engine->camera.position, ray_direction, engine->cfg->map, &dda))
			return (error_print_critical("DDA did not work"), false);
		num_pixels_wall = raycasting_calculate_wall(dda.perpWallDist, engine->screen.y);
		engine_render_column(*engine, x, num_pixels_wall);
		x++;
	}
	return (true);
        //printf("Column %ld\n", x);
        
    	ray_direction = raycasting_new_ray(x, engine->screen.x, engine->camera); 
        /*
        if (!dda_calculate_hit(engine->camera.position, ray_direction, engine->cfg->map, &point_colition, &side))
		{
			printf("%s", "dda not working");
			return (false);
		}
        
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
        //distance = dpoint_calculate_distance(engine->camera.position,  point_colition);
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
//}