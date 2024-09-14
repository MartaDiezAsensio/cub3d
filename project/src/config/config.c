/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:08:30 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/12 19:17:05 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"
#include "config.h"
#include "error.h"
#include "ft_get_next_line.h"

static	void	config_init_vars(t_config *config)
{
	config->map.map = NULL;
	config->map_lines = NULL;
	config->north_texture = NULL;
	config->south_texture = NULL;
	config->east_texture = NULL;
	config->west_texture = NULL;
	config->ceiling_color.r = -1;
	config->ceiling_color.g = -1;
	config->ceiling_color.b = -1;
	config->floor_color.r = -1;
	config->floor_color.g = -1;
	config->floor_color.b = -1;
	config->player_position.x = -1;
	config->player_position.y = -1;
	config->player_orientation = NONE;
	config->valid_cfg = true;
}

bool	config_is_header_initialized(t_config config)
{
	if (config.north_texture == NULL || config.south_texture == NULL || \
			config.east_texture == NULL || config.east_texture == NULL)
		return false;
	if (config.ceiling_color.r < 0 || config.ceiling_color.g < 0 || \
		config.ceiling_color.b < 0)
		return (false);
	if (config.floor_color.r < 0 || config.floor_color.g < 0 || \
		config.floor_color.b < 0)
		return (false);
	return (true);
}

bool	config_init(t_config *cfg, const char *filename)
{
	int fd;

	config_init_vars(cfg);
	fd = open (filename, O_RDONLY);
	if (fd < 0)
		return (error_perror_critical(), false);
	if (!config_load(cfg, fd))
		return (close (fd), false);
	close (fd);
	if (!config_map_list_2_ptr(cfg))
		return (false);
	ft_lstclear(&cfg->map_lines, free);
	return (true);
}

void	config_destroy(t_config *cfg)
{
	ft_ptr_free_double_ptr(cfg->map.map);
//	config_file_destroy_map(cfg);
	if (cfg->map_lines != NULL)
		ft_lstclear(&cfg->map_lines, free);
	if (cfg->north_texture != NULL)
		cfg->north_texture = ft_ptr_free(cfg->north_texture);
	if (cfg->south_texture != NULL)
		cfg->south_texture = ft_ptr_free(cfg->south_texture);
	if (cfg->west_texture != NULL)
		cfg->west_texture = ft_ptr_free(cfg->west_texture);
	if (cfg->east_texture != NULL)
		cfg->east_texture = ft_ptr_free(cfg->east_texture);
}


bool	config_get_trimmed_line(char **trim_line, int fd)
{
	char	*line;
	
	line = ft_get_next_line_many_fds(fd);
	if (line != NULL)
	{
		*trim_line = ft_strtrim(line, "\n\r");
		free (line);
		if (*trim_line == NULL)
			return (false);
	}
	else
		*trim_line = NULL;
	return (true);		
}


#include <stdio.h>

void	config_debug(t_config cfg)
{
	t_list	*node;
	size_t	i;

	printf("DEBUG CONFIG********************************\n");
	printf("\t NO: %s\n", cfg.north_texture);
	printf("\t SO: %s\n", cfg.south_texture);
	printf("\t WE: %s\n", cfg.west_texture);
	printf("\t EA: %s\n", cfg.east_texture);
	printf("\n");
	printf("\t F %d, %d, %d\n", cfg.floor_color.r, cfg.floor_color.g, cfg.floor_color.b);
	printf("\t C %d, %d, %d\n", cfg.ceiling_color.r, cfg.ceiling_color.g, cfg.ceiling_color.b);
	printf("\n");
	printf("\t MAP LIST ***\n");
	node = cfg.map_lines;
	while (node!= NULL)
	{
		printf("\t\t%s", (char *)node->content);
		node = node->next;
	}
	printf("\n");
	printf("\t MAP LIST ***\n");
	printf("\t MAP PTR ***\n");
	i = 0;
	(void)i;

	while (cfg.map.map[i] != NULL)
	{
		printf("\t\t%s", cfg.map.map[i]);
		i++;
	}
	printf("\n");
	printf("\t MAP PTR ***\n");
	printf("DEBUG CONFIG********************************\n");	
}

