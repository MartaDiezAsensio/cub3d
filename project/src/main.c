/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:53:01 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/01 18:23:30 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "engine.h"
#include "map.h"
#include "config.h"
#include "libft.h"

static bool main_validate_args(int argc, char **argv)
{
	size_t	str_len;
	char	*file_ext;

	if (argc != 2)
		return (error_print_critical("Incorrect number of params"), false);
	str_len = ft_strlen(argv[1]);
	file_ext = ft_substr(argv[1], str_len - 4, 4);
	if (file_ext == NULL)
		return (error_perror_critical(), false);
	if (ft_strcmp(file_ext, ".cub") != 0)
	{
		free (file_ext);
		return (error_print_critical("The cfg file is not a .cub file") \
					, false);
	}
	free (file_ext);
	return (true);
}

int	main(int argc, char **argv)
{
	t_engine	engine;
	t_config	cfg;

	if (!main_validate_args(argc, argv))
		return (EXIT_FAILURE);
	if(!config_init(&cfg, argv[1]))
		return (config_destroy(&cfg), EXIT_FAILURE);
	config_debug(cfg);
	if (!config_validator(&cfg))
		return (config_destroy(&cfg), EXIT_FAILURE);
	//config_debug(cfg);
	if (!engine_init(&engine, &cfg))
		return (engine_destroy(&engine), EXIT_FAILURE);
	//printf("Engine: %d  \n", engine.camera.position.y);
	if (!engine_start(&engine))
		return (engine_destroy(&engine), EXIT_FAILURE);
	engine_loop(&engine);
	engine_destroy(&engine);
	return (EXIT_SUCCESS);
}
