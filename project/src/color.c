/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:58:02 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/27 16:24:52 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_new_3(unsigned char _r, unsigned char _g, unsigned char _b)
{
	t_color color;

	color.r = _r;
	color.g = _g;
	color.b = _b;
	color.a = 255;
	return (color);
}

t_color	color_new(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
	t_color color;

	color.r = _r;
	color.g = _g;
	color.b = _b;
	color.a = _a;
	return (color);
}

uint32_t	color_2_mlx(t_color tcolor)
{
	uint32_t	color;

	color = (tcolor.r << 24 | tcolor.g << 16 | tcolor.b << 8 | tcolor.a);
	return (color);
}

uint32_t	color_new_mlx(unsigned char _r, unsigned char _g, unsigned char _b)
{
	t_color color;

	color.r = _r;
	color.g = _g;
	color.b = _b;
	color.a = 0xFF;
	return (color_2_mlx(color));
}
