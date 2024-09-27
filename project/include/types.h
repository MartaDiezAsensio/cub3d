/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:34:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/27 16:05:21 by mdiez-as         ###   ########.fr       */
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
} t_orientations;

#endif
