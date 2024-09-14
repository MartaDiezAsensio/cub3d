/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:24:16 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/07 19:32:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void ft_lstdel_back(t_list **list)
{
	t_list	*last;
	t_list	*pre_last;

	if (*list == NULL)
		return ;
	if (ft_lstsize(*list) == 1)
	{
		ft_lstclear(list, free);
		return ;
	}
	last = *list;
	pre_last = *list;
	while (last != NULL && last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	if (last != NULL && last->next == NULL)
	{
		ft_lstdelone(last, free);
		pre_last->next = NULL;
	}
}