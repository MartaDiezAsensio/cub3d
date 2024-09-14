/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:33:48 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/12 00:24:28 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	size_t	size;
	size_t	start;
	size_t	end;

	size = ft_strlen(s1);
	start = 0;
	while (ft_char_in_set(s1[start], set) == 1 && start < size)
		start++;
	if (start == size)
		return (ft_substr(s1, size, 1));
	end = size;
	while (ft_char_in_set(s1[end - 1], set) == 1 && end > 0)
		end--;
	str_trim = ft_substr(s1, start, end - start);
	return (str_trim);
}
