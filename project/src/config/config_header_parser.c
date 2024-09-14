/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_header_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:41:43 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/08 02:06:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "config.h"
#include "libft.h"
#include "ft_get_next_line.h"
#include "error.h"
#include "color.h"

static bool config_is_texture_line(const char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}

static bool	config_set_texture(t_config *cfg, const char *line)
{
	size_t	length;
	char	*texture;

	length = ft_strlen(line);
	texture = ft_substr(line, 3, length - 3);
	if (texture == NULL)
		return (error_perror_critical(), false);
	if (ft_strncmp(line, "NO ", 3) == 0)
		cfg->north_texture = texture;
	if (ft_strncmp(line, "SO ", 3) == 0)
		cfg->south_texture = texture;
	if (ft_strncmp(line, "WE ", 3) == 0)
		cfg->west_texture = texture;
	if (ft_strncmp(line, "EA ", 3) == 0)
		cfg->east_texture = texture;
	return (true);
}

static	bool	config_parse_colors(t_color *color, const char *colors_line)
{
	char	**token_list;
	size_t	i;
	size_t	color_component;

	token_list = ft_split(colors_line, ',');
	if (token_list == NULL)
		return (error_perror_critical(), false);
	i = 0;
	color->a = 255;
	while (token_list[i] != NULL)
	{
		color_component = ft_atoi(token_list[i]);
		if (i == 0)
			color->r = color_component;
		if (i == 1)
			color->g = color_component;
		if (i == 2)
			color->b = color_component;
		i++;
	}
	ft_ptr_free_double_ptr(token_list);
	return (true);
	
}

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
	if (ft_strncmp(line, "F ", 2) == 0)
		cfg->floor_color = rgb;
	if (ft_strncmp(line, "C ", 2) == 0)
		cfg->ceiling_color = rgb;
	free (str_colors);
	return (true);
}

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
			if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
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
/*
bool	config_parse_header(t_config *cfg, int fd)
{
	char	*line;
	char	*trim_line;

	line = ft_strdup("");
	while (line != NULL)
	{	
		free (line);
		if (config_is_header_initialized(*cfg))
			break;
//		line = ft_get_next_line_many_fds(fd);
		if (!config_get_trimmed_line(&line, fd))
			return (false);
		if (line != NULL && ft_strlen(line) > 0)
		{
			if (ft_strncmp(trim_line, "F ", 2) == 0 || ft_strncmp(trim_line, "C ", 2) == 0)
			{
				if (!config_set_colors(cfg, trim_line))
					return (free(trim_line), false);
			}
			if (config_is_texture_line(trim_line))
			{
				if (!config_set_texture(cfg, trim_line))
					return (free(trim_line), false);
			}
			continue;
		}
	}
	return (true);
}
*/