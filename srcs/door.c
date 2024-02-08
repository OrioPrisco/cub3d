/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:12:37 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/08 14:48:18 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#undef __STRICT_ANSI__
#include "math.h"

#define ANIM_LEN 100

static void	tick_door(t_door *door, t_line *door_line)
{
	t_vec2d	door_vec;
	int		dir;

	if (door->interacted && !door->timer)
		door->timer = ANIM_LEN;
	dir = 1;
	if (door->opened)
		dir = -1;
	door->interacted = false;
	if (door->timer)
	{
		door_vec = vec2d_to(door_line->start, door_line->end);
		door_vec = vec2d_rotate(door_vec, -dir * (M_PI / 2) / ANIM_LEN);
		door_line->end = point_add_vec2d(door_line->start, door_vec);
		door->timer--;
		if (!door->timer)
			door->opened ^= 1;
	}
}

void	tick_doors(t_env *env)
{
	size_t	i;
	t_door	*door;

	i = 0;
	while (i < env->graphics.doors.size)
	{
		door = ((t_door *)env->graphics.doors.data) + i;
		tick_door(door, ((t_line *)env->lines.data) + door->line_id);
		i++;
	}
}
