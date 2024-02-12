/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:51:37 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/02/12 13:18:02 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map.h"
#include <X11/keysym.h>
#undef __STRICT_ANSI__
#include "math.h"
#include "hooks.h"
#include "collision.h"

typedef struct s_xkey_cubkey_map_entry {
	int	xkey;
	int	cubkey;
}	t_xkey_cubkey_map_entry;

static const t_xkey_cubkey_map_entry	g_keymap[] = {
{XK_q, Key_Rot_Left},
{XK_Left, Key_Rot_Left_alt},
{XK_e, Key_Rot_Right},
{XK_Right, Key_Rot_Right_alt},
{XK_w, Key_Up},
{XK_Up, Key_Up_alt},
{XK_s, Key_Down},
{XK_Down, Key_Down_alt},
{XK_a, Key_Left},
{XK_d, Key_Right},
{XK_m, Key_Map,},
};

int	on_keypress(int key, t_env *env)
{
	size_t	i;

	i = 0;
	while (i < sizeof(g_keymap) / sizeof(g_keymap[0]))
	{
		if (key == g_keymap[i].xkey)
			env->held_keys |= (1 << g_keymap[i].cubkey);
		i++;
	}
	if (key == XK_Escape)
		quit_prg(env);
	if (key == XK_f)
		door_interact(env);
	return (0);
}

int	on_keyrelease(int key, t_env *env)
{
	size_t	i;

	i = 0;
	while (i < sizeof(g_keymap) / sizeof(g_keymap[0]))
	{
		if (key == g_keymap[i].xkey)
			env->held_keys &= ~ (1 << g_keymap[i].cubkey);
		i++;
	}
	return (0);
}

static void	handle_movement(t_env *env, t_vec2d dir)
{
	t_vec2d		movement;
	t_player	*player;

	player = &env->player;
	if (!dir.x && !dir.y)
		return ;
	dir = vec2d_mul(vec2d_to_unit(dir), STEP);
	if (!env->bonus)
		return ((void)(player->pos = point_add_vec2d(player->pos, dir)));
	movement = move_player(player, env->lines.data, env->solid_lines, dir);
	if (char_at_map(&env->map, player->pos.x + movement.x,
			player->pos.y + movement.y, ' ') != '1')
		player->pos = point_add_vec2d(player->pos, movement);
}

void	handle_held_keys(t_env *env)
{
	t_vec2d		dir;
	t_player	*player;

	player = &env->player;
	dir = (t_vec2d){0, 0};
	if (env->held_keys & ((1 << Key_Rot_Left) | (1 << Key_Rot_Left_alt)))
		player->look = vec2d_rotate(player->look, -M_PI / 180);
	if (env->held_keys & ((1 << Key_Rot_Right) | (1 << Key_Rot_Right_alt)))
		player->look = vec2d_rotate(player->look, M_PI / 180);
	if (env->held_keys & ((1 << Key_Up) | (1 << Key_Up_alt)))
		dir = point_add_vec2d(dir, player->look);
	if (env->held_keys & ((1 << Key_Down) | (1 << Key_Down_alt)))
		dir = point_add_vec2d(dir, (t_vec2d){-player->look.x, -player->look.y});
	if (env->held_keys & (1 << Key_Left))
		dir = point_add_vec2d(dir, (t_vec2d){player->look.y, -player->look.x});
	if (env->held_keys & (1 << Key_Right))
		dir = point_add_vec2d(dir, (t_vec2d){-player->look.y, player->look.x});
	handle_movement(env, dir);
}
