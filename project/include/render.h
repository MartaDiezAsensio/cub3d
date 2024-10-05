/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:48:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/10/05 23:18:24 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stddef.h>

typedef struct s_render_column
{
	size_t		column;
	int			ceiling_end;
	int			wall_size;
	int			floor_start;
}	t_render_column;

#endif