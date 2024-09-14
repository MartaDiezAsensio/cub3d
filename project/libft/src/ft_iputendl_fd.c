/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:30:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/15 20:26:40 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iputendl_fd(char *s, int fd)
{
	int	num_bytes_str;
	int	num_bytes_nl;
	int	num_bytes;

	num_bytes = 0;
	num_bytes_str = ft_iputstr_fd(s, fd);
	num_bytes_nl = ft_iputchar_fd('\n', fd);
	if (num_bytes_str >= 0)
		num_bytes = num_bytes_str;
	if (num_bytes_nl >= 0)
		num_bytes = num_bytes + num_bytes_nl;
	return (num_bytes);
}
