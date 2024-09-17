/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:08:37 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/17 23:05:52 by gabriel          ###   ########.fr       */
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

#define WIDTH 1024
#define HEIGHT 768

typedef struct s_data
{
	int 		width;
	int			height;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_data;

uint32_t	create_color(unsigned char r, unsigned char g, unsigned char b)
{
	uint32_t	color;
	t_color		tcolor;

	tcolor = color_new_3(r, g, b);
	color = color_2_mlx(tcolor);

	return (color);
}

void	paint_player(t_data *data)
{
	mlx_put_pixel(data->img, data->width / 2, data->height / 2, create_color(0xFF, 0xFF, 0xFF));
}


void	loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	paint_player(data);
}


int	main(int argc, char **argv)
{
	t_data data;

	data.width = WIDTH;
	data.height = HEIGHT;
	(void)argc;
	(void)argv;
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
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}