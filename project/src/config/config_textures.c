/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:24:04 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/08 19:57:16 by mdiez-as         ###   ########.fr       */
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
	char	*trim;

	trim = ft_strtrim(line," \t");
	if (trim == NULL)
		return(error_perror_critical(), false);
	length = ft_strlen(trim);
	texture = ft_substr(trim, 3, length - 3);
	if (texture == NULL)
		return (error_perror_critical(), false);
	if (ft_strncmp(trim, "NO ", 3) == 0)
		return (free(trim), config_save_texture(&cfg->north_texture, \
				&texture, "NO texture duplicated."));
	if (ft_strncmp(trim, "SO ", 3) == 0)
		return (free(trim), config_save_texture(&cfg->south_texture, \
				&texture, "SO texture duplicated."));
	if (ft_strncmp(trim, "WE ", 3) == 0)
		return (free(trim), config_save_texture(&cfg->west_texture, \
				&texture, "WE texture duplicated."));
	if (ft_strncmp(trim, "EA ", 3) == 0)
		return (free(trim), config_save_texture(&cfg->east_texture, \
				&texture, "EA texture duplicated."));
	free (texture);
	free(trim);
	return (true);
}
