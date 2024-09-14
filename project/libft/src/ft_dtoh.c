/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:12:54 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 00:04:27 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	ft_printf_get_hex_char(unsigned long u_number, \
			unsigned int up_case)
{
	char	hex_digit;

	hex_digit = ' ';
	if (u_number < 10)
	{
		hex_digit = '0' + u_number;
		return (hex_digit);
	}
	if (u_number < 16)
	{
		if (up_case == 1)
			hex_digit = 'A' + (u_number - 10);
		else
			hex_digit = 'a' + (u_number - 10);
	}
	return (hex_digit);
}

static size_t	ft_get_hex_digits(unsigned long u_number)
{
	size_t	num_digits;

	num_digits = 1;
	while (u_number / 16 != 0)
	{
		u_number = u_number / 16;
		num_digits++;
	}
	return (num_digits);
}

char	*ft_dtoh(unsigned long u_number, unsigned int up_case)
{
	size_t			num_digits;
	char			*str;
	unsigned long	number;

	number = u_number;
	num_digits = ft_get_hex_digits(number);
	str = (char *)malloc(num_digits + 1);
	if (str == NULL)
		return (NULL);
	str[num_digits] = '\0';
	while (num_digits > 0)
	{
		str[num_digits - 1] = ft_printf_get_hex_char(number % 16, up_case);
		number = number / 16;
		num_digits--;
	}
	return (str);
}
