/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:24:52 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/12 19:16:52 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
//#include <stdlib.h>

#include "config.h"
#include "error.h"

static void	config_report_error(t_config *config, const char * error_msg)
{
	config->valid_cfg = false;
	error_print_critical(error_msg);
}

/*
static bool	config_validate_textures(t_config *cfg)
{
	int	fd;
	
	fd = open(cfg->north_texture, O_RDONLY);
	if (fd < 0)
		return (error_print_critical("North texture cannot be opened"), false);
	close (fd);
	fd = open(cfg->south_texture, O_RDONLY);
	if (fd < 0)
		return (error_print_critical("South texture cannot be opened"), false);
	close (fd);
	fd = open(cfg->west_texture, O_RDONLY);
	if (fd < 0)
		return (error_print_critical("West texture cannot be opened"), false);
	close (fd);
	fd = open(cfg->east_texture, O_RDONLY);
	if (fd < 0)
		return (error_print_critical("East texture cannot be opened"), false);
	close (fd);
	return (true);
}
*/

static void	config_validate_textures(t_config *cfg)
{
	int	fd;
	
	fd = open(cfg->north_texture, O_RDONLY);
	if (fd < 0)
		return (config_report_error(cfg, "North texture cannot be opened"));
	close (fd);
	fd = open(cfg->south_texture, O_RDONLY);
	if (fd < 0)
		return (config_report_error(cfg, "South texture cannot be opened"));
	close (fd);
	fd = open(cfg->west_texture, O_RDONLY);
	if (fd < 0)
		return (config_report_error(cfg, "West texture cannot be opened"));
	close (fd);
	fd = open(cfg->east_texture, O_RDONLY);
	if (fd < 0)
		return (config_report_error(cfg, "East texture cannot be opened"));
	close (fd);
}

static void	config_validate_colors(t_config *cfg)
{

	if (cfg->ceiling_color.r < 0 || cfg->ceiling_color.r > 256)
		return (config_report_error(cfg, "Ceiling colour invalid"));
	if (cfg->ceiling_color.g < 0 || cfg->ceiling_color.g > 256)
		return (config_report_error(cfg, "Ceiling colour invalid"));
	if (cfg->ceiling_color.b < 0 || cfg->ceiling_color.b > 256)
		return (config_report_error(cfg, "Ceiling colour invalid"));
	if (cfg->floor_color.r < 0 || cfg->floor_color.r > 256)
		return (config_report_error(cfg, "Floor colour invalid"));
	if (cfg->floor_color.g < 0 || cfg->floor_color.g > 256)
		return (config_report_error(cfg, "Floor colour invalid"));
	if (cfg->floor_color.b < 0 || cfg->floor_color.b > 256)
		return (config_report_error(cfg, "Floor colour invalid"));
}

bool	config_validator(t_config *cfg)
{
	config_validate_textures(cfg);
	if (!cfg->valid_cfg)
		return (false);
	config_validate_colors(cfg);
	if (!cfg->valid_cfg)
		return (false);
	if (!config_validate_map(cfg))
		return (false);
	if (!cfg->valid_cfg)
		return (false);
	return (true);
}