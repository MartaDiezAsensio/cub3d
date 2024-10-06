/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render_column.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:55:05 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/06 21:19:16 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "render.h"

/*
		Here we paint aa column
		We calculate the end of ceiling , the size of the wall and 
		the start of floor.
		Then we paint ceiling, wall and floor.
*/
bool	engine_render_column(t_engine engine, int x, \
			unsigned int num_pixels_wall, t_dda_raycasting dda)
{
	size_t			i;
	t_render_column	render_col;

	render_col.column = x;
	render_col.wall_size = num_pixels_wall;
	render_col.ceiling_end = engine.screen.middle_y - (num_pixels_wall / 2);
	if (render_col.ceiling_end < 0)
		render_col.ceiling_end = 0;
	render_col.floor_start = engine.screen.middle_y + (num_pixels_wall / 2);
	if ((size_t)render_col.floor_start >= engine.screen.y)
		render_col.floor_start = engine.screen.y - 1;
	i = 0;
	engine_render_paint_ceiling(engine, render_col, &i);
	engine_render_paint_wall(engine, render_col, dda);
	i = render_col.floor_start;
	engine_render_paint_floor(engine, render_col, &i);
	return (true);
}
