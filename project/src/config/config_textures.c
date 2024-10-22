/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:24:04 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 20:42:04 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "config.h"
#include "error.h"

static bool	config_save_texture(char **cfg_path, char **path, \
				const char *error_msg)
{
	if (*cfg_path != NULL)
	{
		free (*path);
		*path = NULL;
		error_print_critical(error_msg);
		return (false);
	}
	else
	{
		*cfg_path = *path;
		return (true);
	}
}

bool	config_set_texture(t_config *cfg, const char *line)
{
	size_t	length;
	char	*texture;

	length = ft_strlen(line);
	texture = ft_substr(line, 3, length - 3);
	if (texture == NULL)
		return (error_perror_critical(), false);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (config_save_texture(&cfg->north_texture, &texture, \
					"NO texture duplicated."));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (config_save_texture(&cfg->south_texture, &texture, \
					"SO texture duplicated."));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (config_save_texture(&cfg->west_texture, &texture, \
					"WE texture duplicated."));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (config_save_texture(&cfg->east_texture, &texture, \
					"WA texture duplicated."));
	free (texture);
	return (true);
}
