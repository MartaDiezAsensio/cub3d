/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:58:34 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/30 20:16:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "MLX42/MLX42.h"

size_t	fps_counter(double *old_time)
{
	//double mlx_get_time(void);
	double time;
	size_t	fps;

	fps = 0;
	time = mlx_get_time();
	if (time - *old_time  != 0.0f)
		fps = 1 / (time - *old_time);
	*old_time = time;
	return (fps);
}