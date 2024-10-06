/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:20:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/06 21:17:15 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine.h"
#include "error.h"
#include "MLX42/MLX42.h"
#include "raycasting.h"
#include "libft.h"

static bool	engine_render_fps(t_engine *engine)
{
	size_t		fps;
	char		*text;
	char		*str_number;

	if (engine->fps_img != NULL)
		mlx_delete_image(engine->mlx, engine->fps_img);
	if (engine->screen.x < 400 || engine->screen.y < 50)
		return (true);
	fps = fps_counter(&engine->time);
	str_number = ft_itoa(fps);
	if (str_number == NULL)
		return (error_perror_critical(), false);
	text = ft_strjoin("fps: ", str_number);
	if (text == NULL)
	{
		free (str_number);
		return (error_perror_critical(), false);
	}
	engine->fps_img = mlx_put_string(engine->mlx, text, engine->screen.x - 90, \
						10);
	free (str_number);
	free (text);
	return (true);
}

/*
	Here we paint the frame and then we render fps text.
*/
static bool	engine_render_create_frame(t_engine *engine)
{
	if (!raycasting_paint(engine))
		return (false);
	if (!engine_render_fps(engine))
		return (false);
	return (true);
}

/*
	Here we render the screen and if we detect an error, we stop the engine.
*/
void	engine_render(void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	if (!engine_render_create_frame(engine))
		engine_stop(engine);
}
