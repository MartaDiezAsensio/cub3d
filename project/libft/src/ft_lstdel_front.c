/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:24:19 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/07 19:26:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void ft_lstdel_front(t_list **list)
{
	t_list *begin;

	if (*list == NULL)
		return ;
	begin = (*list)->next;
	ft_lstdelone(*list, free);
	*list = begin;
}