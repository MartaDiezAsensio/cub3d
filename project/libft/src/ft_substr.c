/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:33:57 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/12 00:26:24 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	size_t	ft_check_size(size_t size_str, size_t len, int start)
{
	size_t	len_new_ptr;

	if (len + start <= size_str)
		len_new_ptr = len;
	else
	{
		if ((size_t)start >= size_str)
			len_new_ptr = 0;
		else
			len_new_ptr = size_str - start;
	}
	return (len_new_ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	size_str;
	size_t	i;

	size_str = ft_strlen(s);
	size = ft_check_size(size_str, len, start);
	substr = (char *)malloc(size + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < size && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
