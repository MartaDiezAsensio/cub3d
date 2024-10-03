/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_resize_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 00:19:52 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 23:43:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "screen.h"
#include "error.h"

void	on_resize(int width, int height, void *param)
{
	t_engine	*engine;
	int32_t		x;
	int32_t		y;

	engine = (t_engine *)param;
	screen_update_size(&engine->screen, width, height);
	if (!mlx_resize_image(engine->img, (uint32_t)width, (uint32_t)height))
	{
		error_print_mlx_perror();
		engine_stop(engine);
		return ;
	}
	//void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);
	mlx_get_mouse_pos(engine->mlx, &x, &y);
	engine->screen.mouse_position.x = x;
	engine->screen.mouse_position.y = y;

}
