/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:30:52 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/14 22:16:39 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iputnbr(unsigned int n, int fd)
{
	char	digit;
	int		num_bytes;

	num_bytes = 0;
	if (n < 10)
	{
		digit = '0' + n;
		return (ft_iputchar_fd(digit, fd));
	}
	num_bytes = ft_iputnbr(n / 10, fd);
	num_bytes = num_bytes + ft_iputnbr(n % 10, fd);
	return (num_bytes);
}

int	ft_iputnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	int				num_bytes;

	num_bytes = 0;
	if (n < 0)
	{
		nbr = n * (-1);
		num_bytes = ft_iputchar_fd('-', fd);
	}
	else
		nbr = n;
	num_bytes = num_bytes + ft_iputnbr(nbr, fd);
	return (num_bytes);
}
