/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:56:15 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/26 16:22:42 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef struct s_engine t_engine;

typedef struct s_color
{
	int r;
	int g;
	int b;
	int	a;

} t_color;

t_color		color_new_3(unsigned char _r, unsigned char _g, unsigned char _b);
t_color		color_new(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a);
uint32_t	color_2_mlx(t_color color);
uint32_t	color_new_mlx(unsigned char _r, unsigned char _g, unsigned char _b);

#endif
