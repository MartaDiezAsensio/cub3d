/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render_column_ceiling.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:55:05 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/02 17:31:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "MLX42/MLX42.h"
#include "color.h"
#include "render.h"


void	engine_render_paint_ceiling(t_engine engine, \
					t_render_column render_col, size_t *i)
{
	uint32_t	sky_color;

	sky_color  = color_2_mlx(engine.cfg->ceiling_color);
	while (*i <= (size_t)render_col.ceiling_end)
	{
		mlx_put_pixel(engine.img, render_col.column, *i, sky_color);
		(*i)++;
	}
}
