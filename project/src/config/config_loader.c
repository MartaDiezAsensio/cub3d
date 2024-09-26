/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:21:15 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/26 16:33:59 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "error.h"
#include "libft.h"
#include "ft_get_next_line.h"

bool	config_load(t_config *cfg, int fd)
{
	if (fd < 0)
		return (error_print_critical("Invalid .cub file"), false);
	if (!config_parse_header(cfg, fd))
		return (false);
	if (!config_parse_map(cfg, fd))
		return (false);
	return (true);
}
