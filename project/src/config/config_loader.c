/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:21:15 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/08 20:24:54 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	
#include "config.h"
#include "error.h"
#include "libft.h"

static bool	config_append_line_2_map(t_config *cfg, const char *line)
{
	t_list	*line_node;
	char	*content;

	content = ft_strdup(line);
	if (content == NULL)
		return (error_perror_critical(), false);
	line_node = ft_lstnew(content);
	if (line_node == NULL)
	{
		return (error_perror_critical(), false);
	}
	ft_lstadd_back(&cfg->map_lines, line_node);
	return (true);
}

bool	config_parse_line(t_config *cfg, const char *line)
{
	size_t	lines_map_read;

	lines_map_read = ft_lstsize(cfg->map_lines);
	if (config_line_is_texture(line))
	{
		if (lines_map_read > 0)
			return (error_print_critical("Wrong cfg line order."), false);
		if (!config_set_texture(cfg, line))
			return (false);
		return (true);
	}
	if (config_line_is_color(line))
	{
		if (lines_map_read > 0)
			return (error_print_critical("Wrong cfg line order."), false);
		if (!config_set_colors(cfg, line))
			return (false);
		return (true);
	}
	if (config_line_is_map(line))
	{
		if (!config_append_line_2_map(cfg, line))
			return (false);
	}
	return (true);
}

static bool	config_treat_line(t_config *cfg, const char *line)
{
	if (!config_line_is_valid(line))
	{
		error_print_critical("Invalid config line found.");
		return (false);
	}
	if (!config_parse_line(cfg, line))
		return (false);
	return (true);
}

bool	config_load(t_config *cfg, int fd)
{
	char	*line;

	if (fd < 0)
		return (error_print_critical("Invalid .cub file"), false);
	line = ft_strdup("");
	while (line != NULL)
	{
		free (line);
		if (!config_line_get_trimmed(&line, fd))
			return (false);
		if (line != NULL && ft_strlen(line) > 0)
		{
			if (!config_treat_line(cfg, line))
				return (free(line), false);
		}
		if (line != NULL && ft_strlen(line) == 0 && \
					ft_lstsize(cfg->map_lines) > 0)
		{
			error_print_critical("Found empty line inside map");
			return (free(line), false);
		}
	}
	return (true);
}
