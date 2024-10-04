/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:31:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/03 17:34:07 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcontains(t_list *list, void *content, int (*f)(void *c1, \
			void *c2))
{
	t_list	*node;

	if (list == NULL)
		return (0);
	if (content == NULL)
		return (0);
	node = list;
	while (node != NULL)
	{
		if ((*f)(node->content, content) == 0)
			return (1);
		node = node->next;
	}
	return (0);
}
