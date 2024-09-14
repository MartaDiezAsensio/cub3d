/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_mlx_config.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:16:53 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/11 19:37:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"

#include "engine.h"
#include "events.h"

/*
	We set the settings, it starts MAXIMIZED and STRECH is for the case
	that you resize the window, it automaticaly resizes the image linked 
	to the window.

	//I have tested MLX_STRETCH IMAGE and it does NOT print correcctly the 
		half of the screen.
*/
void	engine_mlx_settings(void)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	//mlx_set_setting(MLX_STRETCH_IMAGE, true);
}

void	engine_mlx_hooks(t_engine *engine)
{
	mlx_key_hook(engine->mlx, on_keydown, engine);
	mlx_loop_hook(engine->mlx, engine_render, engine);
	mlx_close_hook(engine->mlx, on_destroy, engine);
	mlx_resize_hook(engine->mlx, on_resize, engine);

}