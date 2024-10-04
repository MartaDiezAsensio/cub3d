/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:21:15 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/04 08:23:49 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	
#include "config.h"
#include "error.h"
#include "libft.h"

/*
bool	config_load(t_config *cfg, int fd)
{
	if (fd < 0)
		return (error_print_critical("Invalid .cub file"), false);
	if (!config_parse_header(cfg, fd))
		return (false);
	if (!config_parse_map(cfg, fd))
		return (false);
	return (true);
}
*/

/*
bool	config_parse_map(t_config *cfg, int fd)
{
	t_list	*line_node;
	char	*line;
	char	*content;

	line = ft_strdup("");
	while (line != NULL)
	{
		free (line);
		if (!config_get_trimmed_line(&line, fd))
			return(error_print_critical("Error in map line when parsing"), \
						false);
		if (line != NULL && ft_strlen(line) > 0)
		{
			content = ft_strdup(line);
			if (content == NULL)
				return(error_perror_critical(), false);
			line_node = ft_lstnew(content);
			if (line_node == NULL)
			{
				free (line);
				return (error_perror_critical(), false);
			}
			ft_lstadd_back(&cfg->map_lines, line_node);
		}
	}
	return (true);	
}

*/

static bool	config_append_line_2_map(t_config *cfg, const char *line)
{
	t_list	*line_node;
	char	*content;

	content = ft_strdup(line);
	if (content == NULL)
		return(error_perror_critical(), false);
	line_node = ft_lstnew(content);
	if (line_node == NULL)
	{
//		free (line);
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
		if(lines_map_read > 0)
			return (error_print_critical("Wrong cfg line order."),false);
		if (!config_set_texture(cfg, line))
			return (false);
		return (true);
	}
	if (config_line_is_color(line))
	{
		if(lines_map_read > 0)
			return (error_print_critical("Wrong cfg line order."),false);
		if (!config_set_colors(cfg, line))
			return (false);
		return (true);
	}
	if (config_line_is_map(line))
	{
		if (!config_append_line_2_map(cfg, line))
			return (false);
		return (true);
	}
	return (true);
}

#include <stdio.h>
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
			if (!config_line_is_valid(line))
			{
				error_print_critical("Invalid config line found.");
				return (free(line), false);
			}
			if(!config_parse_line(cfg, line))
				return (free(line), false);
		}
		if (line != NULL && ft_strlen(line) == 0 && ft_lstsize(cfg->map_lines) > 0)
		{
			error_print_critical("Found empty line inside map");
			return (free(line), false);
		}
	}
	return (true);
}

/*
bool	config_file_load(t_config_file *cfg, int fd)
{
	char *line;

	if (fd < 0)
		return (error_print_critical("Invalid .cub file"), false);
	line = ft_strdup("");
	if (line == NULL)
		return (error_perror_critical(), false);
	while (line != NULL)
	{
		free (line);
		line = ft_get_next_line_many_fds(fd);
		if (line != NULL && ft_strelen(line) > 0)
		{
			if (!config_file_parse_line(cfg, line))
				return (error_print_critical("Config option not supported") , false);
		}
	}
	return (true);
}
*/