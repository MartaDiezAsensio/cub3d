/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:31:59 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/12 00:22:08 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;
	size_t	size_s1;
	size_t	size_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str_joined = (char *)malloc(size_s1 + size_s2 + 1);
	if (str_joined == NULL)
		return (NULL);
	ft_strlcpy(str_joined, s1, size_s1 + 1);
	ft_strlcat(str_joined, s2, size_s1 + size_s2 + 1);
	return (str_joined);
}
