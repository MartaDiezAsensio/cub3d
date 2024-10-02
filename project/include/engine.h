/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:43:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/02 20:47:55 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "screen.h"
# include "camera.h"
# include "map.h"
# include "texture.h"
# include "config.h"
# include "dda.h"
# include "MLX42/MLX42.h"
# include "render.h" 

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

	double		time;
	mlx_image_t	*fps_img;
	
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

//engine/engine_render.c
bool	engine_render_column(t_engine engine, int x, unsigned int num_pixels_wall, t_dda_raycasting	dda);
void	engine_render(void *param);

//engine/fps_counter.c
size_t	fps_counter(double *old_time);


//engine/engine_render_column_ceiling.c

void	engine_render_paint_ceiling(t_engine engine, \
					t_render_column render_col, size_t *i);

//engine/engine_render_column_floor.c
void	engine_render_paint_floor(t_engine engine, \
					t_render_column render_col, size_t *i);

//engine/engine_render_column_wall.c
bool engine_render_paint_wall(t_engine engine, t_render_column render_col, \
				 t_dda_raycasting dda);
//bool engine_gabriel(t_engine engine, t_dda_raycasting dda, int sky_end, int floor_start, int screen_height, unsigned int num_pixels_wall, int i, int x);
					
#endif
