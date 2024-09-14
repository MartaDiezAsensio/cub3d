/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:31:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/12 20:37:13 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcontains(t_list *list, void *content, int (*f)(void *c1, \
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