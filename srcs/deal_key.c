/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:51:37 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/01/17 17:27:22 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
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

void	handle_held_keys(t_env *env)
{
	if (env->held_keys & ((1 << Key_Rot_Left) | (1 << Key_Rot_Left_alt)))
		env->player.look = vec2d_rotate(env->player.look, -M_PI / 180);
	if (env->held_keys & ((1 << Key_Rot_Right) | (1 << Key_Rot_Right_alt)))
		env->player.look = vec2d_rotate(env->player.look, M_PI / 180);
	if (env->held_keys & ((1 << Key_Up) | (1 << Key_Up_alt)))
		move_player(&env->player, &env->lines, env->bonus,
			vec2d_mul(env->player.look, STEP));
	if (env->held_keys & ((1 << Key_Down) | (1 << Key_Down_alt)))
		move_player(&env->player, &env->lines, env->bonus,
			vec2d_mul(vec2d_rotate(env->player.look, M_PI), STEP));
	if (env->held_keys & (1 << Key_Left))
		move_player(&env->player, &env->lines, env->bonus,
			vec2d_mul(vec2d_rotate(env->player.look, -M_PI / 2), STEP));
	if (env->held_keys & (1 << Key_Right))
		move_player(&env->player, &env->lines, env->bonus,
			vec2d_mul(vec2d_rotate(env->player.look, M_PI / 2), STEP));
}
