/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:43:09 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/11 00:01:48 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "screen.h"
//#include "MLX42/MLX42.h"

bool	screen_init(t_screen *screen)
{
	screen->x = SCREEN_DEFAULT_WIDTH;
	screen->y = SCREEN_DEFAULT_HEIGH;
	screen->middle_y = screen->y / 2;
	screen->title = ft_strdup(SCREEN_DEFAULT_TITLE);
	if (screen->title == NULL)
		return (false);
	screen->resize = true;
	return (true);
}

void	screen_destroy(t_screen *screen)
{
	if (screen->title != NULL)
	{
		free (screen->title);
		screen->title = NULL;
	}
}

void	screen_update_size(t_screen *screen, int x, int y)
{
	screen->x = x;
	screen->y = y;
	screen->middle_y = screen->y / 2;
}
