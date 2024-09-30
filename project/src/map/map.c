/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:14:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/30 19:52:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"
#include "libft.h"
#include "error.h"

#include <stdio.h>

void	map_destroy(t_map *map)
{
	size_t	i;

	i = 0;
	if (map->map != NULL)
	{
		while (i < map->height)
		{
			if (map->map[i] != NULL)
				free (map->map[i]);
			i++;
		}
		free (map->map);
		map->map = NULL;
		map->height = 0;
		map->width = 0;
	}
}

bool	map_is_inside(t_map map, int col, int row)
{
	if (col < 0 || col >= (int)map.width)
		return (false);
	if (row < 0 || row >= (int)map.height)
		return (false);
	return (true);
}

static bool	map_generate_padding(int len, char **padding)
{
	if (len <= 0)
	{
		*padding = NULL;
		return (true);
	}
	*padding = (char *)malloc(len);
	if  (*padding == NULL)
		return (error_perror_critical(), false);
	*padding = ft_memset(*padding, ' ', len - 1);
	(*padding)[len - 1] = '\0';
	return (true);
}

bool	map_normalize(t_map *map)
{
	size_t	i;
	size_t	len;
	char	*padding;
	char	*aux;
	i = 0;
	while (map->map[i] != NULL)
	{
		padding = NULL;
		len = ft_strlen(map->map[i]);
		if (!map_generate_padding(map->width - len, &padding))
			return (false);
		if (padding != NULL)
		{
			aux = map->map[i];
			map->map[i] = ft_strjoin(map->map[i], padding);
			free (aux);
			free (padding);
			if (map->map[i] == NULL)
				return (error_print_critical("Fail normalizing map."), false);
		}
		i++;
	}
	return (true);
}