/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:24:40 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/14 01:26:44 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_num_digits(unsigned int nb)
{
	unsigned int	num_digits;

	num_digits = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		num_digits++;
	}
	return (num_digits);
}

static void	ft_get_characters( char *ch_number, unsigned int size,
			unsigned int number)
{
	int				i;
	unsigned int	digit;

	i = size - 1;
	while (i >= 0)
	{
		digit = (number % 10);
		ch_number[i] = '0' + digit;
		number = number / 10;
		i--;
	}
}

char	*ft_utoa(unsigned int n)
{
	char			*number;
	unsigned int	size;

	size = ft_num_digits(n);
	number = (char *)malloc(size + 1);
	if (number == NULL)
		return (NULL);
	ft_get_characters(number, size, n);
	number[size] = '\0';
	return (number);
}
