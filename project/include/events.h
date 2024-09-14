/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:59:42 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/11 19:02:16 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "MLX42/MLX42.h"

void	on_keydown(mlx_key_data_t keydata, void *param);
void	on_destroy(void *param);
void	on_resize(int width, int height, void *param);

#endif