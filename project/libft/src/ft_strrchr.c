/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:33:37 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/12 00:24:13 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*occurrence;
	char	character;

	character = (char)c;
	occurrence = NULL;
	while (*s != '\0')
	{
		if (*s == character)
			occurrence = (char *)s;
		s++;
	}
	if (*s == character)
		return ((char *)s);
	else
		return (occurrence);
}
