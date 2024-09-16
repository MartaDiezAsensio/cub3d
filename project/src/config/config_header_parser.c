/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_header_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:41:43 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/16 21:37:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "config.h"
#include "libft.h"
#include "ft_get_next_line.h"
#include "error.h"
#include "color.h"

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
