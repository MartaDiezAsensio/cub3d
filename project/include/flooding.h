/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:03:20 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 18:21:29 by greus-ro         ###   ########.fr       */
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

// flooding_neighbours.c
bool	flood_add_neighbours(t_config cfg, t_flooding *flood, t_tile tile);

#endif
