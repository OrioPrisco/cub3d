/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:28:31 by mpeulet           #+#    #+#             */
/*   Updated: 2024/02/12 14:22:30 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "hooks.h"

#define ANIM_SPEED 100
#define ANIM_FRAMES 4

void	animate_sprite(t_env *env)
{
	size_t		i;
	t_sprite	*spr;

	i = 0;
	while (i < env->graphics.sprites.size)
	{
		spr = ((t_sprite *)env->graphics.sprites.data) + i;
		env->timer++;
		env->timer %= ANIM_SPEED * ANIM_FRAMES;
		((size_t *)env->graphics.line_textures_id.data)[spr->line_id]
			= env->timer / ANIM_SPEED;
		i++;
	}
}
