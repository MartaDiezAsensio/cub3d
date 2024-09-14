/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:21:15 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/07 20:36:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "error.h"
#include "libft.h"
#include "ft_get_next_line.h"

bool	config_load(t_config *cfg, int fd)
{
	if (fd < 0)
		return (error_print_critical("Invalid .cub file"), false);
	if (!config_parse_header(cfg, fd))
		return (false);
	if (!config_parse_map(cfg, fd))
		return (false);
//	if (!config_map_list_2_ptr(cfg))
//		return (false);
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