/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_paint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:15:21 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/22 13:53:29 by mdiez-as         ###   ########.fr       */
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
    return (screen_height / distance);   
}

bool    raycasting_paint(t_engine *engine)
{

    // Para cada columna de pixels...
        // se genera la direccion del rayo de la columna de pixels
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

	x = 0;

//double	point_calculate_xdist(t_point point1, t_point point2)

	while(x < engine->screen.x)
	{
		ray_direction = raycasting_new_ray(x, engine->screen.x, engine->camera); 
        if (!dda_calculate_hit(engine->camera.position, ray_direction, engine->cfg->map, &point_colition))
		{
			printf("%s", "dda not working");
			return (false);
		}
        if (!vector_get_orientation(ray_direction, &orientation))
        {
            printf("%s", "Orientation not working\n");
            return(false);
        }
        
        if (orientation == NORTH || orientation == SOUTH)
            distance = dpoint_calculate_ydist(engine->camera.position, point_colition);
        if (orientation == WEST || orientation == EAST)
            distance = dpoint_calculate_xdist(engine->camera.position, point_colition);
        
        //distance = dpoint_calculate_distance(engine->camera.position,  point_colition);
        //distance = 0.3f;
        num_pixels_wall = raycasting_calculate_wall(distance, engine->screen.y);
        printf("\t\t  %f\n", distance);
        engine_render_column(*engine, x, num_pixels_wall);
        //revisasr si hace falta liberar recursos.
        x++;
    }
    printf("\n\n\n\n");
    return (true);
}