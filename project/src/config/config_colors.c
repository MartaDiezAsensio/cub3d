/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:27:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 21:31:47 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "config.h"
#include "error.h"

static	bool	config_color_check_num_canals(char **tokens)
{
	size_t	i;

	i = 0;
	while(tokens[i] != NULL)
		i++;
	if (i != 3)
		return (error_print_critical("The colour does NOT have 3 channels"), \
					false);
	return (true);
}

static bool	config_color_valid_chars(const char *token)
{
	size_t	i;

	i = 0;
	while (token[i] != '\0')
	{
		if (token[i] != '+' && token[i] != '-' && !ft_isdigit(token[i]) \
				&& token[i] != ' ')
		{
			error_print_critical("A colour channel has invalid value.");
			return (false);
		}
		i++;
	}
	return (true);
}

static void	color_save(int color_component, size_t order, t_color *color)
{
	if (order == 0)
		color->r = color_component;
	if (order == 1)
		color->g = color_component;
	if (order == 2)
		color->b = color_component;
}

static bool	config_parse_colors(t_color *color, const char *colors_line)
{
	char	**token_list;
	size_t	i;
	int	color_component;

	token_list = ft_split(colors_line, ',');
	if (token_list == NULL)
		return (error_perror_critical(), false);
	if(!config_color_check_num_canals(token_list))
		return(ft_ptr_free_double_ptr(token_list),false);
	i = 0;
	color->a = 255;
	while (token_list[i] != NULL)
	{
		if(!config_color_valid_chars(token_list[i]))
			return(ft_ptr_free_double_ptr(token_list),false);
		color_component = ft_atoi(token_list[i]);
		if (color_component < 0 || color_component > 255)
		{
			ft_ptr_free_double_ptr(token_list);
			return (error_print_critical("One color has invalid value."), false);
		}
		color_save(color_component, i, color);
		i++;
	}
	ft_ptr_free_double_ptr(token_list);
	return (true);
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
