/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:25:00 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/12 00:26:51 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*next;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	next = (*lst);
	*lst = new;
	new->next = next;
}
