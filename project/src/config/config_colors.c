/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:27:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/08 20:24:39 by mdiez-as         ###   ########.fr       */
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

static bool	config_check_color_line(const char *trim, t_config *cfg, \
				t_color rgb)
{
	if (ft_strncmp(trim, "F ", 2) == 0)
	{
		if (!config_set_floor_color(cfg, rgb))
			return (false);
	}
	if (ft_strncmp(trim, "C ", 2) == 0)
	{
		if (!config_set_ceiling_color(cfg, rgb))
			return (false);
	}
	return (true);
}

bool	config_set_colors(t_config *cfg, const char *line)
{
	size_t	length;
	char	*str_colors;
	t_color	rgb;
	char	*trim;

	trim = ft_strtrim(line, " \t");
	if (trim == NULL)
		return (error_perror_critical(), false);
	length = ft_strlen(trim);
	str_colors = ft_substr(trim, 2, length -2);
	if (str_colors == NULL)
		return (free(trim), error_perror_critical(), false);
	if (!config_parse_colors(&rgb, str_colors))
		return (free(trim), free (str_colors), false);
	free (str_colors);
	if (!config_check_color_line(trim, cfg, rgb))
		return (free(trim), false);
	free(trim);
	return (true);
}
