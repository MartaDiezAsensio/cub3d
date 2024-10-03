/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_header_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:41:43 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 19:55:38 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "config.h"
#include "libft.h"
#include "ft_get_next_line.h"
#include "error.h"
#include "color.h"
#include "map.h"

static	bool	config_set_colors(t_config *cfg, const char *line)
{
	size_t	length;
	char	*str_colors;
	t_color	rgb;
	
	length = ft_strlen(line);
	str_colors = ft_substr(line, 2, length -2);
	if (str_colors == NULL)
		return (error_perror_critical(), false);
	if (!config_parse_colors(&rgb, str_colors))
		return (free (str_colors), false);
	free (str_colors);
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (cfg->floor_color.r < 0)
			cfg->floor_color = rgb;
		else
			return (error_print_critical("Found Colour F duplicated."), false);			
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (cfg->ceiling_color.r < 0)
			cfg->ceiling_color = rgb;
		else
			return (error_print_critical("Found Colour C duplicated."), false);
	}
	return (true);
}

static	bool	config_is_valid_header_line(const char *line)
{
	if (config_is_color_line(line) || config_is_texture_line(line))
		return (true);
	return (false);
}

static	bool	config_is_valid_line(const char *line)
{
	if (map_cell_is_valid(line[0]) || config_is_valid_header_line(line))
		return (true);
	return (false);
}

#include <stdio.h>

bool	config_parse_header(t_config *cfg, int fd)
{
	char	*line;

	line = ft_strdup("");
	while (line != NULL)
	{	
		free (line);
//		if (config_is_header_initialized(*cfg))
//			break;
		if (!config_get_trimmed_line(&line, fd))
			return (false);
		if (line != NULL && ft_strlen(line) > 0)
		{
			if(!config_is_valid_line(line))
			{
				error_print_critical("Found invalid config line");
				return (free(line), false);
			}
			if(config_is_valid_header_line(line))
			{
				if (config_is_color_line(line))
				{
					if (!config_set_colors(cfg, line))
						return (free(line), false);
					continue;
				}
				if (config_is_texture_line(line))
				{
					if (!config_set_texture(cfg, line))
						return (free(line), false);
					continue;
				}
				printf("Salida linea incorrecta _%s_\n", line);
				return (free(line), true);
			}
			else
				return (free(line), true);
		}
	}
	printf("Salida while\n");
	return (true);
}
/*
bool	config_parse_header(t_config *cfg, int fd)
{
	char	*line;

	line = ft_strdup("");
	while (line != NULL)
	{	
		free (line);
		if (config_is_header_initialized(*cfg))
			break;
		if (!config_get_trimmed_line(&line, fd))
			return (false);
		if (line != NULL && ft_strlen(line) > 0)
		{
			if (config_is_color_line(line))
			{
				if (!config_set_colors(cfg, line))
					return (free(line), false);
			}
			if (config_is_texture_line(line))
			{
				if (!config_set_texture(cfg, line))
					return (free(line), false);
			}
			continue;
		}
	}
	return (true);
}
*/