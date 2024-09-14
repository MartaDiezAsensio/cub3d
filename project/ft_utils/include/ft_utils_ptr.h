/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ptr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:10:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/13 00:14:04 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_PTR_H
# define FT_UTILS_PTR_H

void	*ft_ptr_free(void *ptr);
void	*ft_ptr_char_free_and_null(char **ptr);
void	*ft_ptr_int_free_and_null(int **ptr);
void	*ft_matrix_char_free(char **matrix);
void	*ft_matrix_int_free(int **matrix);

#endif