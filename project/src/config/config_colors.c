/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:27:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/26 16:32:31 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "error.h"

static void	color_save(int color_component, size_t order, t_color *color)
{
	if (order == 0)
		color->r = color_component;
	if (order == 1)
		color->g = color_component;
	if (order == 2)
		color->b = color_component;
}

bool config_is_color_line(const char * line)
{
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (true);
	return (false);
}

bool	config_parse_colors(t_color *color, const char *colors_line)
{
	char	**token_list;
	size_t	i;
	int	color_component;

	token_list = ft_split(colors_line, ',');
	if (token_list == NULL)
		return (error_perror_critical(), false);
	i = 0;
	color->a = 255;
	while (token_list[i] != NULL)
	{
		color_component = ft_atoi(token_list[i]);
		if (color_component < 0 || color_component > 255)
			return (error_print_critical("One color has invalid value."), false);
		color_save(color_component, i, color);
		i++;
	}
	ft_ptr_free_double_ptr(token_list);
	return (true);
}
