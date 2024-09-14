/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:43:14 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/11 20:12:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "libft.h"
#include "MLX42/MLX42.h"


void	error_print_warning(const char *msg)
{
	ft_putendl_fd("Warning", STDOUT_FILENO);
	ft_putstr_fd("\t", STDOUT_FILENO);
	ft_putendl_fd((char *)msg, STDOUT_FILENO);
}

void	error_print_critical(const	char *msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putstr_fd("\t", STDERR_FILENO);
	ft_putendl_fd((char *)msg, STDERR_FILENO);
}

void	error_perror_warning(void)
{
	perror("Warning\n\t");
}

void	error_perror_critical(void)
{
	perror("Error\n\t");
}

void	error_print_mlx_perror(void)
{
	char	*str_mlx_error;

	str_mlx_error = (char *)mlx_strerror(mlx_errno);
	if (str_mlx_error == NULL)
	{
		error_print_critical("Cannot get the mlx errno error.");
		return ;
	}
	error_print_critical(str_mlx_error);
	free(str_mlx_error);
}