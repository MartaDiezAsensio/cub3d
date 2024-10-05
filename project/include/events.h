/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:59:42 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/05 23:13:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "MLX42/MLX42.h"

void	on_keydown(mlx_key_data_t keydata, void *param);
void	on_destroy(void *param);
void	on_resize(int width, int height, void *param);
void	on_mouse_move_event(double xpos, double ypos, void *param);

#endif
