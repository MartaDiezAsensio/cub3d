/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_paint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:15:21 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/09/20 08:12:10 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "vector.h"
#include "dda.h"
#include "tile.h"
#include "error.h"
#include "point.h"

//t_vector    raycasting_new_ray(int x, int w, t_camera camera);
//t_tile *dda_calculate_hit(t_point	origin, t_vector direction, t_map map);
//double	point_calculate_distance(t_point point1, t_point point2)

static int  raycasting_calculate_wall(double distance, int screen_height)
{
    (void)distance;
    (void)screen_height;
    return (500);   
}

//#include <>

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
    size_t      x;
    t_vector    ray_direction;
    t_point     point_colition;
    double      distance;
    int         num_pixels_wall;


    x = 0;
    (void)ray_direction;
    (void)point_colition;
    while(x < engine->screen.x)
    {
        //ray_direction = raycasting_new_ray(x, engine->screen.x, engine->camera);
        //if (!dda_calculate_hit(engine->camera.position, ray_direction, engine->map, &point_colition))
        //    return (false);
        //distance = point_calculate_distance(engine->camera.position,  point_colition);
        distance = 0.3f;
        num_pixels_wall = raycasting_calculate_wall(distance, engine->screen.y);
        engine_render_column(*engine, x, num_pixels_wall);
        //revisasr si hace falta liberar recursos.
        x++;
    }
    return (true);
}