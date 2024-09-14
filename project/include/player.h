/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:29:37 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/31 19:04:19 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vector.h"
# include "point.h"
typedef	struct s_player
{
	t_point			position;
	t_orientations	orientation;
//	float		angle_orientation;
//	t_vector	orientation;
	
}	t_player;

#endif