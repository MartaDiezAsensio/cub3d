/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:58:34 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 17:51:06 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"

size_t	fps_counter(double *old_time)
{
	double	time;
	size_t	fps;

	fps = 0;
	time = mlx_get_time();
	if (time - *old_time != 0.0f)
		fps = 1.0f / (time - *old_time);
	*old_time = time;
	return (fps);
}
