/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_destroy_event.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:04:58 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/11 19:10:46 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "engine.h"

void on_destroy(void *param)
{
	t_engine *engine;

	(void)engine;
	engine = (t_engine *)param;
}

/*
int on_destroy(void *param)
{
	t_engine *engine;

	engine = (t_engine *)param;
	engine_destroy(engine);
	exit(EXIT_SUCCESS);
	return (0);
}
*/