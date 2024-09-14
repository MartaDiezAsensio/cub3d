/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:29:03 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/23 17:51:37 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

void	*free_ptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_substr(const char *src, size_t start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size;

	size = ft_strlen(src);
	if (start + len < size)
		size = len;
	else
	{
		if (start > size)
			size = 0;
		else
			size = size - start;
	}
	substr = (char *)malloc(size + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		substr[i] = src[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	ft_strchr(char *src, char *c)
{
	int	pos;
	int	i;

	pos = 0;
	while (src[pos] != '\0')
	{
		i = 0;
		while (c[i] != '\0')
		{
			if (c[i] == src [pos])
				return (pos);
			i++;
		}
		pos++;
	}
	return (-1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	char	*joined;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	joined = (char *)malloc(size_s1 + size_s2 + 1);
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joined[size_s1 + i] = s2[i];
		i++;
	}
	joined[size_s1 + i] = '\0';
	return (joined);
}
