/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:09:40 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/02 15:28:22 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "hooks.h"
#include "draw.h"
#include "mlx.h"
#include <X11/X.h>
#include <stdlib.h>
#include "mini_map.h"

//TODO : tweak angle ? a bit twitchy at small movements
// but feel pretty nice at big movements
static void	do_mouse_stuff(t_env *env)
{
	int		x;
	int		y;
	double	angle;

	if (!mlx_mouse_get_pos(env->mlx, env->win, &x, &y))
		return ;
	if (env->held_keys & (1 << Key_Map))
		return ;
	if (x < 0 || y < 0 || x > env->frame->width || y > env->frame->height)
		return ;
	angle = env->angles[x];
	env->player.look = vec2d_rotate(env->player.look, angle);
	mlx_mouse_move(
		env->mlx, env->win, env->frame->width / 2, env->frame->height / 2);
}

//TODO : only draw after something changes
int	my_loop_hook(t_env *env)
{
	handle_held_keys(env);
	switch_frame(env);
	if (env->held_keys & (1 << Key_Map))
		render_mini_map(env->frame, &env->map, &env->player, env->map.width);
	else
	{
		render_mini_map(&env->mini_map, &env->map, &env->player, 12);
		draw_screen(env->frame, &env->player, env);
		cpy_img(env->frame, &env->mini_map);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->frame->img, 0, 0);
	do_mouse_stuff(env);
	return (0);
}

int	my_expose(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->frame->img, 0, 0);
	return (0);
}

int	quit_prg(t_env *env)
{
	destroy_env(env);
	exit(0);
}

void	register_hooks(t_env *env)
{
	mlx_expose_hook(env->win, my_expose, env);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask, &quit_prg, env);
	mlx_hook(env->win, KeyPress, KeyPressMask, &on_keypress, env);
	mlx_hook(env->win, KeyRelease, KeyReleaseMask, &on_keyrelease, env);
	mlx_loop_hook(env->mlx, my_loop_hook, env);
}
