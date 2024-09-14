/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:24:40 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/11 23:49:41 by greus-ro         ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	char			*number;
	unsigned int	nbr;
	unsigned int	size;
	unsigned int	i;

	size = 0;
	i = 0;
	if (n < 0)
	{
		size++;
		nbr = n * (-1);
	}
	else
		nbr = n;
	size = size + ft_num_digits(nbr);
	number = (char *)malloc(size + 1);
	if (number == NULL)
		return (NULL);
	if (n < 0)
		number[i++] = '-';
	ft_get_characters(number + i, size - i, nbr);
	number[size] = '\0';
	return (number);
}
