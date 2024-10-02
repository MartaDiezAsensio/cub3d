/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:32:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/02 20:26:05 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <math.h>
#include "dda.h"
#include "error.h"

static t_dda	dda_init(t_dpoint origin, t_vector direction)
{
	t_dda	dda_data;

	dda_data.x = origin.x;
	dda_data.y = origin.y;
	dda_data.final = dpoint_new(origin.x + direction.x * \
			1000.0f, origin.y + direction.y * 1000.0f);
	dda_data.dx = dda_data.final.x - dda_data.x;
	dda_data.dy = dda_data.final.y - dda_data.y;
	if (fabs(dda_data.dx) >= fabs(dda_data.dy))
		dda_data.step = fabs(dda_data.dx);
	else
		dda_data.step = fabs(dda_data.dy);
	dda_data.dx = dda_data.dx / dda_data.step;
	dda_data.dy = dda_data.dy / dda_data.step;
	return (dda_data);
}

static void	dda_next_step(t_dda *dda)
{
	dda->x = dda->x + dda->dx;
	dda->y = dda->y + dda->dy;
}

bool	dda_calculate_hit(t_dpoint	origin, t_vector direction, t_map map, \
		t_dpoint *hit)
{
	t_dda		dda_data;
	int			i;
	t_dpoint	point;

	dda_data = dda_init(origin, direction);
	i = 0;
	while (i <= (int)dda_data.step)
	{
		point = dpoint_new(dda_data.x, dda_data.y);
		if (!map_is_inside(map, point.x, point.y))
			return (error_print_critical("Ray does not find hit."), false);
		if (map_cell_is_wall(map, point.x, point.y))
		{
			*hit = point;
			hit->x = (int) point.x;
			hit->y = (int) point.y;
			return (true);
		}
		dda_next_step(&dda_data);
		i++;
	}
	return (error_print_critical("Ray does not find hit."), false);
}
