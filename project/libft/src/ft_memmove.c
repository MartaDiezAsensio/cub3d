/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:29:52 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/13 01:40:43 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static void	ft_memmove_rev(unsigned char *dest, unsigned char *src, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		dest[i - 1] = src[i - 1];
		i--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	dest_ptr = (unsigned char *) dest;
	src_ptr = (unsigned char *) src;
	if (src_ptr < dest_ptr)
		ft_memmove_rev(dest_ptr, src_ptr, n);
	else
		ft_memcpy(dest_ptr, src_ptr, n);
	return (dest);
}
