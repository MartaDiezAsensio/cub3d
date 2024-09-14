/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:40:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/11 20:01:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	error_print_warning(const char *msg);
void	error_print_critical(const	char *msg);
void	error_perror_warning(void);
void	error_perror_critical(void);
void	error_print_mlx_perror(void);

#endif