/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:31:22 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/12 00:08:14 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*string;
	char	character;

	string = (char *)s;
	character = (char)c;
	while (*string != '\0')
	{
		if (*string == character)
			return (string);
		string++;
	}
	if (*string == character)
		return (string);
	return (NULL);
}
