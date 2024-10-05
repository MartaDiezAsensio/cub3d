/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:27:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/06 01:28:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "config.h"
#include "error.h"

static bool	config_set_floor_color(t_config *cfg, t_color rgb)
{
	if (cfg->floor_color.r < 0)
	{
		cfg->floor_color = rgb;
		return (true);
	}
	else
		return (error_print_critical("Found Colour F duplicated."), false);
}

static bool	config_set_ceiling_color(t_config *cfg, t_color rgb)
{
	if (cfg->ceiling_color.r < 0)
	{
		cfg->ceiling_color = rgb;
		return (true);
	}
	else
		return (error_print_critical("Found Colour C duplicated."), false);
}

bool	config_set_colors(t_config *cfg, const char *line)
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
		if (!config_set_floor_color(cfg, rgb))
			return (false);
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (!config_set_ceiling_color(cfg, rgb))
			return (false);
	}
	return (true);
}
