/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:43:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/27 16:03:16 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "screen.h"
# include "camera.h"
# include "map.h"
# include "texture.h"
# include "config.h"
# include "MLX42/MLX42.h"

# define ROTATION_ANGLE 0.05f
# define MOV_SPEED 0.3f

enum e_engine_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum	e_engine_textures
{
	TEXTURE_NORTH = 0,
	TEXTURE_SOUTH = 1,
	TEXTURE_WEST = 2,
	TEXTURE_EAST = 3
};

typedef	struct s_engine
{
	mlx_t		*mlx;
	t_camera	camera;
	t_config	*cfg;
	t_screen	screen;
	t_texture	textures[4];

	mlx_image_t	*img;
	
}	t_engine;

//engine/
bool	engine_init(t_engine *engine, t_config *cfg);
bool	engine_start(t_engine *engine);
void	engine_stop(t_engine *engine);
void	engine_loop(t_engine *engine);
void	engine_destroy(t_engine *engine);

//engine/engine_texture.c
bool	engine_texture_load(const char *filename, t_texture *texture);
bool	engine_textures_load(t_engine *engine);
void	engine_textures_destroy(t_engine *engine);

//engine/engine_config.c
void	engine_mlx_settings(void);
void	engine_mlx_hooks(t_engine *engine);

//engine/render
bool	engine_render_column(t_engine engine, int x, unsigned int num_pixels_wall);
void	engine_render(void *param);

#endif
