/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:08:37 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/18 21:15:43 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//#include "error.h"
//#include "engine.h"
//#include "map.h"
//#include "config.h"
//#include "libft.h"
#include "types.h"
#include "color.h"
#include "MLX42/MLX42.h"
#include "raycasting.h"
#include "vector.h"
#include "camera.h"
#include "map.h"

//#define WIDTH 640
//#define HEIGHT 480
#define WIDTH 800
#define HEIGHT 600

#define WIDTH_MAP 3


typedef struct s_data
{
	int 		width;
	int			height;
	t_camera	camera;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		map;
	
}	t_data;

uint32_t	create_color(unsigned char r, unsigned char g, unsigned char b)
{
	uint32_t	color;
	t_color		tcolor;

	tcolor = color_new_3(r, g, b);
	color = color_2_mlx(tcolor);
	return (color);
}

/*DDA algorithm****************************************************/
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
	if(point.x < 0 || point.y < 0)
		return (false);
	if(point.x > (int)map.width || point.y > (int)map.height)
		return(false);
	return (true);
}
/*
static t_tile *dda_check_hit(t_point point, t_map map)
{
	(void)point;
	(void)map;
	return (NULL);
}
*/

//https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)

#include <stdio.h>
t_tile *dda_calculate_hit2(t_point	origin, t_vector direction,t_data *data)
{
	t_dda		dda_data;
	int			i;
	t_point		point;
	uint32_t	color;

	color = create_color(0xAA, 0x00, 0x00);
	dda_data = dda_init(origin, direction);
	i = 0;
	//printf("dx : %f dy: %f\n",dda_data.dx,dda_data.dy);
	//printf("origin.x %d origin.y %d destiny.x %d destiny.y %d \n", origin.x, origin.y, dda_data.final.x, dda_data.final.y);
	printf("STEP es: %f \n", dda_data.step);
	while( i <= dda_data.step)
	{
		point = point_new(round(dda_data.x), round(dda_data.y));
		if (!dda_is_inside_map(point, data->map))
			return (NULL);
		(void)data;
		//printf("Punto: ");
		mlx_put_pixel(data->img, point.x, point.y, color);
		//tile = dda_check_hit(point, map);
		//if (tile != NULL)
		//	return (tile);
		dda_next_step(&dda_data);
		i++;
	}
	return (NULL);
}

/*END DDA*********************************************************/



void	paint_player(t_data *data)
{
	mlx_put_pixel(data->img, data->width / 2, data->height / 2, create_color(0xFF, 0xFF, 0xFF));
	mlx_put_pixel(data->img, data->width / 2 + 1, data->height / 2, create_color(0xFF, 0xFF, 0xFF));
	mlx_put_pixel(data->img, data->width / 2, data->height / 2 + 1, create_color(0xFF, 0xFF, 0xFF));
	mlx_put_pixel(data->img, data->width / 2 + 1, data->height / 2 + 1, create_color(0xFF, 0xFF, 0xFF));

	/*
	mlx_put_pixel(data->img, data->width / 2, data->height / 2 + 2, create_color(0xFF, 0xFF, 0xFF));
	mlx_put_pixel(data->img, data->width / 2 + 1, data->height / 2 + 2, create_color(0xFF, 0xFF, 0xFF));
	mlx_put_pixel(data->img, data->width / 2, data->height / 2 + 1 + 2, create_color(0xFF, 0xFF, 0xFF));
	mlx_put_pixel(data->img, data->width / 2 + 1, data->height / 2 + 1 + 2, create_color(0xFF, 0xFF, 0xFF));
	*/
}

//bool		raycasting_n_ray(int w, t_camera camera, t_vector **rays);
//t_vector	raycasting_new_ray(int x, int w, t_camera camera);
void	loop(void *param)
{
	t_data		*data;
	size_t		i;
	t_vector	ray_direction;

	data = (t_data *)param;
	
	i = 0;
	//while(i < (size_t)data->width)
	while(i <= (size_t)WIDTH_MAP)
	{
		//ray_direction = raycasting_new_ray(i, data->width, data->camera);
		ray_direction = raycasting_new_ray(i, WIDTH_MAP, data->camera);
		dda_calculate_hit2(data->camera.position, ray_direction, data);
		i++;
	}
	paint_player(data);
}


static	t_data	data_init(void)
{
	t_data	data;
	t_point	origin;
	
	data.width = WIDTH;
	data.height = HEIGHT;
	origin = point_new(data.width / 2, data.height /2);
	data.camera = camera_new(origin, WEST);
	printf("Camera pane: x %f  y %f \n", data.camera.camera_panel.x, data.camera.camera_panel.y);
	printf("Camera direction: x %f y %f \n", data.camera.direction.x, data.camera.direction.y);
	//data.camera.camera_panel.x = 0.1;
	data.map.height = data.height;
	data.map.width = data.width;
	return (data);
}


int	main(void)
{
	t_data data;

	data = data_init();
	data.mlx = mlx_init(WIDTH, HEIGHT, "Test raycasting", false);
	if (data.mlx == NULL)
	{
		printf("ERROR MLX\n");
		return (EXIT_FAILURE);
	}
	data.img = mlx_new_image(data.mlx,data.width, data.height);
	mlx_image_to_window(data.mlx, data.img,0,0);
	mlx_loop_hook(data.mlx, loop, &data);
	mlx_loop(data.mlx);
	printf("EXIT loop\n");
	mlx_delete_image(data.mlx, data.img);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}