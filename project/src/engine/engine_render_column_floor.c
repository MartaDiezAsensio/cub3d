/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render_column_floor.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:55:05 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/03 17:48:12 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "MLX42/MLX42.h"
#include "color.h"
#include "render.h"

void	engine_render_paint_floor(t_engine engine, \
					t_render_column render_col, size_t *i)
{
	uint32_t	floor_color;

	floor_color = color_2_mlx(engine.cfg->floor_color);
	while (*i < engine.screen.y)
	{
		mlx_put_pixel(engine.img, render_col.column, *i, floor_color);
		(*i)++;
	}
}
