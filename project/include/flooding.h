/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:03:20 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/12 22:02:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOODING_H
# define FLOODING_H

# include "types.h"
# include "config.h"
# include "libft.h"

typedef struct s_flooding
{
	t_list	*to_visit;
	t_list	*visited;
	bool	is_open;
	
}	t_flooding;

//flooding.c
bool	flood_map(t_config config, bool *is_closed);

// flooding_utils.c
void	flood_destroy(t_flooding *flood);
bool	flood_init(t_config cfg, t_flooding *flood);
bool	flood_is_tile_in_list(t_list *list, t_tile tile);

// flooding_neighbours.c
bool	flood_add_neighbours(t_config cfg, t_flooding *flood, t_tile tile);


#endif