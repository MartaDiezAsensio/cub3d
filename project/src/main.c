/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:53:01 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/02 19:02:51 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "error.h"
#include "engine.h"
#include "map.h"
#include "config.h"
#include "libft.h"


static bool path_is_file(const char *path)
{
	int		fd;
	char	buffer[1];
	int		error;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_perror_critical(), false);
	error = read(fd,buffer, 1);
	close(fd);
	if(error < 0)
		return (error_print_critical("Arg is a Directory."), false);
	return(true);
}

static bool main_validate_args(int argc, char **argv)
{
	size_t	str_len;
	char	*file_ext;

	if (argc != 2)
		return (error_print_critical("Incorrect number of params"), false);
	str_len = ft_strlen(argv[1]);
	if (str_len <= 4 )
		return (error_print_critical("Incorrect file extension"), false);
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
	if(!path_is_file(argv[1]))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_engine	engine;
	t_config	cfg;
	printf("PRE- PASA 2\n");
	if (!main_validate_args(argc, argv))
		return (EXIT_FAILURE);
	printf("PRE- PASA\n");
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
