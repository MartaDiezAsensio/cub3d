/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:46:11 by greus-ro          #+#    #+#             */
/*   Updated: 2024/08/26 22:20:59 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_ptr_free(void *ptr)
{
	if (ptr != NULL)
		free (ptr);
	return (NULL);
}

char	*ft_ptr_new_char_buffer(size_t size)
{
	char	*buffer;

	buffer = ft_calloc(size + 1, 1);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

void	ft_ptr_free_double_ptr(char **ptr)
{
	size_t	i;

	if (ptr != NULL)
	{
		i = 0;
		while (ptr[i] != NULL)
		{
			free (ptr[i]);
			i++;
		}
		free (ptr);
		ptr = NULL;
	}
}
