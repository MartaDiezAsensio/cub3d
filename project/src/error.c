/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:43:14 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/27 16:25:08 by mdiez-as         ###   ########.fr       */
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

/* We  must NOT do a free because it is a const char * 
from an internal array of mlx it nos not created by malloc*/
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
}
