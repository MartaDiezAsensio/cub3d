/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_mouse_event.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:04:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/05 23:49:14 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "engine.h"

static float	calculate_angle(double deltaX, t_orientations orientation)
{
	float	angle;

	angle = 0.0f;
	if (deltaX < 0.0f)
	{
		if (orientation == EAST || orientation == WEST)
			angle = -ROTATION_SPEED;
		if (orientation == NORTH || orientation == SOUTH)
			angle = ROTATION_SPEED;
	}
	if (deltaX > 0.0f)
	{
		if (orientation == EAST || orientation == WEST)
			angle = ROTATION_SPEED;
		if (orientation == NORTH || orientation == SOUTH)
			angle = -ROTATION_SPEED;
	}
	return (angle);
}

void	on_mouse_move_event(double xpos, double ypos, void *param)
{
	t_engine	*engine;
	float		angle;

	engine = (t_engine *)param;
	angle = calculate_angle(engine->screen.mouse_position.x - xpos, \
				engine->cfg->player_orientation);
	camera_rotate(&engine->camera, angle);
	engine->screen.mouse_position.x = xpos;
	engine->screen.mouse_position.y = ypos;
}
