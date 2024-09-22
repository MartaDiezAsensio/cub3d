/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_key_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:05:06 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/23 01:19:58 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
# include <X11/keysym.h>
# include <X11/X.h>
*/

#include "events.h"
#include "engine.h"
#include "vector.h"

void	on_keydown(mlx_key_data_t keydata, void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	(void)engine;
	printf("Key pressed %d\n", keydata.key);
	if (keydata.key == MLX_KEY_RIGHT)
	{
		engine->camera.direction = vector_rotate(engine->camera.direction, ROTATION_ANGLE, false);
		engine->camera.camera_panel =  vector_rotate(engine->camera.camera_panel, ROTATION_ANGLE, false);
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		engine->camera.direction = vector_rotate(engine->camera.direction, -ROTATION_ANGLE, false);
		engine->camera.camera_panel =  vector_rotate(engine->camera.camera_panel, -ROTATION_ANGLE, false);
	}
	if (keydata.key == MLX_KEY_ESCAPE)
		engine_stop(engine);
}
/*
int	on_keydown(int key_code, void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	(void)engine;
	printf("Key pressed %d\n", key_code);
	if (key_code == XK_Escape)
	{
		engine_destroy(engine);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
*/