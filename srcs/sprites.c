/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:28:31 by mpeulet           #+#    #+#             */
/*   Updated: 2024/02/12 14:54:00 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "env.h"

#define ANIM_SPEED 500
#define ANIM_FRAMES 4
#define ANIM_OFFSET 5

void	animate_sprite(t_env *env, double angle)
{
	size_t		i;
	t_sprite	*spr;
	t_vec2d		offset;
	t_vec2d		offset_neg;

	offset = vec2d_rotate((t_vec2d){0.5, 0}, angle);
	offset_neg = vec2d_mul(offset, -1);
	i = 0;
	while (i < env->graphics.sprites.size)
	{
		spr = ((t_sprite *)env->graphics.sprites.data) + i;
		((t_line *)env->lines.data)[spr->line_id]
			= (t_line){point_add_vec2d(spr->center, offset_neg),
			point_add_vec2d(spr->center, offset)};
		env->timer++;
		env->timer %= ANIM_SPEED * ANIM_FRAMES;
		((size_t *)env->graphics.line_textures_id.data)[spr->line_id]
			= ANIM_OFFSET + (env->timer / ANIM_SPEED);
		i++;
	}
}
