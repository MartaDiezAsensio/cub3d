/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:02:14 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/17 00:06:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "radiants.h"

double	angle_to_radiants(double angle)
{
	double radiants;

	radiants = angle * (M_PI / 180.0f);
	return (radiants);	
}