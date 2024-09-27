/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_map_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:00:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/27 23:57:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "config.h"
#include "libft.h"
#include "ft_get_next_line.h"
#include "error.h"


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

bool	config_map_list_2_ptr(t_config *cfg)
{
	size_t	number_lines;
	size_t	i;
	t_list	*node;
	
	number_lines = ft_lstsize(cfg->map_lines);
	printf("\t\t\t\tNUMBER_LINES %zu\n", number_lines);
	//cfg->map.map = (char **)malloc((number_lines + 1) * sizeof(char *));
	cfg->map.map = (char **)malloc((number_lines + 1) * sizeof(char *));
	if (cfg->map.map == NULL)
		return (error_perror_critical(), false);
	i = 0;
	while (i < number_lines + 1)
		cfg->map.map[i++] = NULL;
	i = 0;
	node = cfg->map_lines;
	while (i < number_lines)
	{
		cfg->map.map[i] = ft_strdup((char *)node->content);
		if (cfg->map.map[i] == NULL)
			return (error_perror_critical(), false);
		cfg->map.width = ft_strlen(cfg->map.map[i]);
		node = node->next;
		i++;
	}
	cfg->map.map[i] = NULL;
	cfg->map.height = number_lines;
	return (true);
}
