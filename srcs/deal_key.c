/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:51:37 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/01/11 00:26:00 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <X11/keysym.h>
#undef __STRICT_ANSI__
#include "math.h"

int	deal_key(int key, t_env *env)
{
	if (key == XK_Q || key == XK_Left)
		env->player.look = vec2d_rotate(env->player.look, -M_PI / 180);
	if (key == XK_E || key == XK_Right)
		env->player.look = vec2d_rotate(env->player.look, M_PI / 180);
	if (key == XK_W || key == XK_Up)
		env->player.pos = point_add_vec2d(env->player.pos, env->player.look);
	if (key == XK_S || key == XK_Down)
		env->player.pos = point_add_vec2d(env->player.pos,
				vec2d_rotate(env->player.look, M_PI));
	if (key == XK_A)
		env->player.pos = point_add_vec2d(env->player.pos,
				vec2d_rotate(env->player.look, -M_PI / 2));
	if (key == XK_D)
		env->player.pos = point_add_vec2d(env->player.pos,
				vec2d_rotate(env->player.look, M_PI / 2));
	return (0);
}
