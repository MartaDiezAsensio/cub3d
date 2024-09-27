/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:40:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/27 16:03:20 by mdiez-as         ###   ########.fr       */
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
