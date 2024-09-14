/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_resize_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 00:19:52 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/11 20:13:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "screen.h"
#include "error.h"

//void mlx_resize_hook(mlx_t* mlx, mlx_resizefunc func, void* param);
void	on_resize(int width, int height, void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	screen_update_size(&engine->screen, width, height);
	if (!mlx_resize_image(engine->img, (uint32_t)width, (uint32_t)height))
	{
		error_print_mlx_perror();
		engine_stop(engine);
		return ;
	}
}
