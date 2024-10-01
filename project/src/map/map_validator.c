/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:43:22 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/01 18:25:52 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "map.h"
#include "libft.h"

#include <stdio.h>

static bool	check_line_is_wall_or_empty(char *line_map)
{
	size_t	x;

	x = 0;
	while (line_map[x] != '\0')
	{
		if (line_map[x] != MAP_TILE_VOID && line_map[x] != MAP_TILE_WALL)
		{
			printf("CHECK: La linea incorrecta es x: %ld, char : %c \n", x,line_map[x]);
			return (false);
		}
		x++;
	}
	printf("CHECK: line ok \n");
	return (true);
}

static bool	get_trimmed_size(const char *line, size_t *len)
{
	char	*trimmed_line;

	trimmed_line  = ft_strtrim(line, " ");
	if (trimmed_line == NULL)	
		return (false);
	*len = ft_strlen(trimmed_line);
	free(trimmed_line);
	return (true);
}

//static bool	check_line(char *line, size_t len_line, size_t len_top, size_t len_bottom)
static bool	check_line(const char *line, size_t len_line, const char *line_top, const char *line_bottom)
{
	size_t	x;
	size_t	len_top;
	size_t	len_bottom;
	
	x = 0;
	if (!get_trimmed_size(line_top, &len_top))
		return (false);
	if (!get_trimmed_size(line_bottom, &len_bottom))
		return (false);
	while(x < len_line)
	{
		if (x < len_line - 2 && line[x] == ' ' && (line[x + 1] != ' ' && line[x + 1] != '1'))
			return (false);
		if (len_line > len_top && x > len_top && line[x] != '1')
			return (false);
		if (len_line > len_bottom && x > len_bottom && line[x] != '1')
			return (false);
		x++;
	}
	return (true);
}

/*
As such, I came up with a few map validation rules. Assume that we are scanning the map from top to bottom, left to right :

    Ignore all leading whitespaces.
    If the current row is the 0th row or the final row, only accept '1's and ' 's.
        else, The first and final character should always be a '1'.
    In the case of any non leading whitespaces, the only acceptable characters adjacent to the space are '1's or ' 's.
    If strlen(curr_row) > strlen(row_on_top) && current col > strlen(row_on_top), current character should be '1'
    If strlen(curr_row) > strlen(row_on_bottom) && current col > strlen(row_on_bottom), current character should be '1'

Those rules should pass all the map requirements given.
*/
bool	map_validator(t_map map)
{
	size_t	y;
	char	*line;
	size_t	len;

	printf("INIT\n");
	if (!check_line_is_wall_or_empty(map.map[0]) || \
			!check_line_is_wall_or_empty(map.map[map.height - 1]))
		return (false);
	y = 1;
	printf("PRE-While\n");
	while (y < map.height - 1)
	{
		printf("validate line %ld\n",y);
		line = ft_strtrim(map.map[y]," ");
		printf("line original : _%s_ trimmed: _%s_\n", map.map[y], line);
		if (line == NULL)
			return (false);
//		len = ft_strlen(map.map[y]);
		len = ft_strlen(map.map[y]);
		printf("Validando que el inicio y final de linea sea paredes %c y %c . \n",  line[0], line[len -1]);
		if (line[0] != MAP_TILE_WALL || line[len - 1] != MAP_TILE_WALL)
			return(free(line), false);
		printf("Validando la linea con la top y bottom\n");
		if (!check_line (line, len, map.map[y - 1], map.map[y + 1]))
			return (free (line), false);
		free (line);
		y++;
	}
	printf("END\n");
	return (true);
}
