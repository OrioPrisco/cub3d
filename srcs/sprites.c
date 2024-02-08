/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:28:31 by mpeulet           #+#    #+#             */
/*   Updated: 2024/02/08 18:32:10 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "hooks.h"

void	animate_sprite(t_env *env)
{
	size_t	i;
	size_t	pos;

	i = 0;
	while (i < env->graphics.sprites_id.size)
	{
		pos = ((size_t *)env->graphics.sprites_id.data)[i];
		env->timer++;
		if (env->timer <= 100)
			((size_t *)env->graphics.line_textures_id.data)[pos] = 0;
		else if (env->timer <= 200)
			((size_t *)env->graphics.line_textures_id.data)[pos] = 1;
		else if (env->timer <= 300)
			((size_t *)env->graphics.line_textures_id.data)[pos] = 2;
		else if (env->timer <= 400)
			((size_t *)env->graphics.line_textures_id.data)[pos] = 3;
		else if (env->timer <= 500)
			env->timer = 0;
		i++;
	}
}
