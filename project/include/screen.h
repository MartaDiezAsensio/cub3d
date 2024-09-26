/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:28:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/26 16:23:19 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "types.h"

# define SCREEN_DEFAULT_WIDTH	90
# define SCREEN_DEFAULT_HEIGH	40
# define SCREEN_DEFAULT_TITLE	"Cube3d 2. Now, it is Personal..."

typedef struct s_screen
{
	size_t	x;
	size_t	y;
	size_t	middle_y;
	char	*title;
	bool	resize;

}	t_screen;

bool	screen_init(t_screen *screen);
void	screen_destroy(t_screen *screen);
void	screen_update_size(t_screen *screen, int x, int y);

#endif
