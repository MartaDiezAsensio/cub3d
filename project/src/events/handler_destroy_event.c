/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_destroy_event.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:04:58 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/05 23:48:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine.h"

void	on_destroy(void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	(void)engine;
}
