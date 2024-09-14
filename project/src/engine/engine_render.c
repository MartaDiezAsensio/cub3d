/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:20:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/11 20:02:05 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "engine.h"
#include "error.h"
#include "MLX42/MLX42.h"


static void	engine_render_background(t_engine *engine)
{
	size_t	i;
	size_t	j;
	t_color	color;
	uint32_t	rgbacolor;

	i = 0;
	while (i < engine->img->width)
	{
		j = 0;
		while(j < engine->img->height)
		{
			if (j < engine->screen.middle_y)
				color =  engine->cfg->ceiling_color;
			else
				color = engine->cfg->floor_color;
			rgbacolor = color_2_mlx(color);
			mlx_put_pixel(engine->img, i,j,rgbacolor);
			j++;
		}
		i++;
	}
}

static bool	engine_render_create_frame(t_engine *engine)
{
	engine_render_background(engine);
	return (true);
}

//https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html
void	engine_render(void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	if (!engine_render_create_frame(engine))
	{
		engine_stop(engine);
		//engine_destroy(engine);
		//exit(EXIT_FAILURE);
	}
}	

