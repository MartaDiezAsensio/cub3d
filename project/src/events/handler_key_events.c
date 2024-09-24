/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_key_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:05:06 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/24 19:39:53 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "events.h"
#include "engine.h"
#include "vector.h"


static bool	check_safe_move(mlx_key_data_t keydata, t_map map, t_camera camera)
{
	int	x;
	int	y;
	t_vector	strafe_dir;

	printf("x original %f y original %f\n",camera.position.x,camera.position.y);
	if(keydata.key == MLX_KEY_W)
	{
		x = camera.position.x + MOV_SPEED * camera.direction.x;
		y = camera.position.y + MOV_SPEED * camera.direction.y;
	}
	if(keydata.key == MLX_KEY_S)
	{
		x = camera.position.x - MOV_SPEED * camera.direction.x;
		y = camera.position.y - MOV_SPEED * camera.direction.y;
	}
	if(keydata.key == MLX_KEY_A)
	{
		strafe_dir =vector_rotate(camera.direction, -M_PI / 2, false);
		x = camera.position.x + MOV_SPEED * strafe_dir.x;
		y = camera.position.y + MOV_SPEED * strafe_dir.y;
	}
	if(keydata.key == MLX_KEY_D)
	{
		strafe_dir =vector_rotate(camera.direction, M_PI / 2, false);
		x = camera.position.x + MOV_SPEED * strafe_dir.x;
		y = camera.position.y + MOV_SPEED * strafe_dir.y;
	}

	if (y < 0 || y > (int)map.height)
	{
		printf("\t\t Y negativa ny %d\n",y);
		return (false);
	}
	if (x < 0 || x > (int)map.width)
	{
		printf("\t\t X negativa nx %d\n",x);
		return (false);
	}
	if (map.map[y][x] ==  MAP_TILE_WALL)
	{
		printf("\t\t WALL x %d y%d\n",x,y);
		return (false);
	}
	return (true);
}


static void	move(mlx_key_data_t keydata, t_engine *engine)
{
	float		x;
	float		y;
	t_vector	strafe_dir;

	printf("move de kkey %d\n", keydata.key);
	if(keydata.key == MLX_KEY_W)
	{
		x = engine->camera.position.x + MOV_SPEED * engine->camera.direction.x;
		y = engine->camera.position.y + MOV_SPEED * engine->camera.direction.y;
	}
	if(keydata.key == MLX_KEY_S)
	{
		x = engine->camera.position.x - MOV_SPEED * engine->camera.direction.x;
		y = engine->camera.position.y - MOV_SPEED * engine->camera.direction.y;
	}
	if(keydata.key == MLX_KEY_A)
	{
		strafe_dir =vector_rotate(engine->camera.direction, -M_PI / 2, false);
		x = engine->camera.position.x + MOV_SPEED * strafe_dir.x;
		y = engine->camera.position.y + MOV_SPEED * strafe_dir.y;
	}
	if(keydata.key == MLX_KEY_D)
	{
		strafe_dir =vector_rotate(engine->camera.direction, M_PI / 2, false);
		x = engine->camera.position.x + MOV_SPEED * strafe_dir.x;
		y = engine->camera.position.y + MOV_SPEED * strafe_dir.y;
	}
	engine->camera.position.x = x;
	engine->camera.position.y = y;
}

void	on_keydown(mlx_key_data_t keydata, void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	(void)engine;
	printf("Key pressed %d\n", keydata.key);

	if (engine->cfg->player_orientation == EAST || engine->cfg->player_orientation == WEST)
	{
		if (keydata.key == MLX_KEY_RIGHT)
		{
			engine->camera.direction = vector_rotate(engine->camera.direction, -ROTATION_ANGLE, false);
			engine->camera.camera_panel =  vector_rotate(engine->camera.camera_panel, -ROTATION_ANGLE, false);
		}
		if (keydata.key == MLX_KEY_LEFT)
		{
			engine->camera.direction = vector_rotate(engine->camera.direction, ROTATION_ANGLE, false);
			engine->camera.camera_panel =  vector_rotate(engine->camera.camera_panel, ROTATION_ANGLE, false);
		}
	}
	if (engine->cfg->player_orientation == NORTH || engine->cfg->player_orientation == SOUTH)
	{
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
	}
	/*
	if(keydata.key == MLX_KEY_A)
	{
		engine->camera.position.x++;
	}
	if(keydata.key == MLX_KEY_D)
	{
		engine->camera.position.x--;
	}
	*/
	
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
	{
		if (check_safe_move(keydata, engine->cfg->map, engine->camera))
			move(keydata, engine);
	}
	/*
	if(keydata.key == MLX_KEY_W)
	{
		engine->camera.position.x = engine->camera.position.x + MOV_SPEED * engine->camera.direction.x;
		engine->camera.position.y = engine->camera.position.y + MOV_SPEED * engine->camera.direction.y;
	}
	if(keydata.key == MLX_KEY_S)
	{
		engine->camera.position.x = engine->camera.position.x - MOV_SPEED * engine->camera.direction.x;
		engine->camera.position.y = engine->camera.position.y - MOV_SPEED * engine->camera.direction.y;
	}
	*/
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