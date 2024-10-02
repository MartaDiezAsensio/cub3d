/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:02:14 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/02 20:43:04 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "radiants.h"

double	angle_to_radiants(double angle)
{
	double	radiants;

	radiants = angle * (M_PI / 180.0f);
	return (radiants);
}
