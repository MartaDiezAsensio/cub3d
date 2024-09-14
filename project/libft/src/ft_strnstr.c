/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:33:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/12 00:23:38 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*occurrence;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 1;
			occurrence = (char *)(big + i);
			while (i + j < len && occurrence[j] != '\0'
				&& little[j] != '\0' && occurrence[j] == little[j])
				j++;
			if (little[j] == '\0')
				return (occurrence);
		}
		i++;
	}
	return (NULL);
}
