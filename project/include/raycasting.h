/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:03:17 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/10/05 23:10:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "engine.h"
# include "camera.h"

t_vector	raycasting_new_ray(int x, int w, t_camera camera);
bool		raycasting_n_ray(int w, t_camera camera, t_vector **rays);
bool		raycasting_paint(t_engine *engine);

#endif
