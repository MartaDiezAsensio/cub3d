/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:36:38 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/06 17:14:04 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <limits.h>

# ifndef OPEN_MAX
#  include <stdio.h>
#  define OPEN_MAX FOPEN_MAX
# endif

char		*ft_get_buffer(char *buffer);
char		*ft_get_next_line_many_fds(int fd);

#endif
