/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:53:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/06 00:54:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "types.h"
# include "color.h"
# include "libft.h"
# include "point.h"
# include "map.h"

typedef struct s_config
{
	t_map			map;
	t_list			*map_lines;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	t_color			floor_color;
	t_color			ceiling_color;
	t_dpoint		player_position;
	t_orientations	player_orientation;
	bool			valid_cfg;
}	t_config;

//config.c
bool	config_init(t_config *cfg, const char *filename);
void	config_destroy(t_config *cfg);
bool	config_is_header_initialized(t_config config);

//config_loader.c
bool	config_load(t_config *cfg, int fd);

//config_header_parser.c
bool	config_parse_header(t_config *cfg, int fd);

//config_map_parser.c
bool	config_parse_map(t_config *cfg, int fd);
bool	config_map_list_2_ptr(t_config *cfg);

//config_validator.c
bool	config_validator(t_config *cfg);
void	config_debug(t_config cfg);

//config_validator_map.c
bool	config_validate_map(t_config *cfg);
bool	config_get_trimmed_line(char **line, int fd);

//config_texture.c
//bool	config_is_texture_line(const char *line);
bool	config_set_texture(t_config *cfg, const char *line);

//config_colors.c
bool	config_set_colors(t_config *cfg, const char *line);

//config/config_colors_parser.c
bool	config_parse_colors(t_color *color, const char *colors_line);

//config/config_line.c
bool	config_line_get_trimmed(char **trim_line, int fd);
bool	config_line_is_color(const char *line);
bool	config_line_is_texture(const char *line);
bool	config_line_is_valid(const char *line);
bool	config_line_is_map(const char *line);

#endif
