/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:59:42 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/27 16:03:26 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "MLX42/MLX42.h"

void	on_keydown(mlx_key_data_t keydata, void *param);
void	on_destroy(void *param);
void	on_resize(int width, int height, void *param);

#endif
