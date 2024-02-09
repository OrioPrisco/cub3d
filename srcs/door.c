/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:12:37 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/09 13:40:06 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "hooks.h"
#undef __STRICT_ANSI__
#include "math.h"
#include "raycast.h"

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
		door_vec = vec2d_rotate(door_vec, -dir * (M_PI / 2 - 0.01) / ANIM_LEN);
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

static void	set_door_interact(size_t line_index, t_vector *door_vec)
{
	size_t	i;
	t_door	*door;

	i = 0;
	door = door_vec->data;
	while (i++ < door_vec->size)
	{
		if (door->line_id == line_index)
		{
			door->interacted = true;
			return ;
		}
		door++;
	}
}

#define INTERACTION_RANGE2 25

void	door_interact(t_env *env)
{
	t_point	point;
	int		hit;
	t_line	ray;

	ray = (t_line)
	{env->player.pos, point_add_vec2d(env->player.pos, env->player.look)};
	hit = ray_lines_intersect(&point, env->lines.data, ray, env->lines.size);
	if (hit != -1 && distance2(env->player.pos, point) < INTERACTION_RANGE2)
		set_door_interact(hit, &env->graphics.doors);
}
