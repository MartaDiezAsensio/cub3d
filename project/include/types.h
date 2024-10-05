/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:34:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/05 23:16:59 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stddef.h>
# include <stdbool.h>

typedef enum e_orientations
{
	NONE,
	NORTH,
	EAST,
	SOUTH,
	WEST
}	t_orientations;

#endif
