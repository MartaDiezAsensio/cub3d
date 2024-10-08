/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:23:16 by greus-ro          #+#    #+#             */
/*   Updated: 2024/10/08 20:09:21 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_removable_char(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
		|| c == '\f')
		return (1);
	return (0);
}

static int	ft_check_sign(char **nbr)
{
	int	sign;

	if (ft_isdigit(**nbr) == 1)
		return (1);
	sign = 1;
	while (**nbr != '\0' && (**nbr == '-' || **nbr == '+' || \
								ft_is_removable_char(**nbr)))
	{
		if (**nbr == '-')
			sign = sign * (-1);
		(*nbr)++;
	}
	return (sign);
}

int	ft_atoi(const char *nbr)
{
	int		total;
	int		sign;
	char	*number;

	number = (char *)nbr;
	while (*number != '\0' && ft_is_removable_char(*number) == 1)
		number++;
	sign = ft_check_sign(&number);
	if (sign == 0)
		return (0);
	total = 0;
	while (*number != '\0')
	{
		if (ft_isdigit(*number) == 1)
			total = total * 10 + (*number - '0');
		else
			return (total * sign);
		number++;
	}
	return (total * sign);
}
