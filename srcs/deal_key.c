/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:51:37 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/01/11 16:35:02 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <X11/keysym.h>
#undef __STRICT_ANSI__
#include "math.h"

#define STEP 0.1

int	deal_key(int key, t_env *env)
{
	if (key == XK_q || key == XK_Left)
		env->player.look = vec2d_rotate(env->player.look, -M_PI / 180);
	if (key == XK_e || key == XK_Right)
		env->player.look = vec2d_rotate(env->player.look, M_PI / 180);
	if (key == XK_w || key == XK_Up)
		env->player.pos = point_add_vec2d
			(env->player.pos, vec2d_mul(env->player.look, STEP));
	if (key == XK_s || key == XK_Down)
		env->player.pos = point_add_vec2d(env->player.pos,
				vec2d_mul(vec2d_rotate(env->player.look, M_PI), STEP));
	if (key == XK_a)
		env->player.pos = point_add_vec2d(env->player.pos,
				vec2d_mul(vec2d_rotate(env->player.look, -M_PI / 2), STEP));
	if (key == XK_d)
		env->player.pos = point_add_vec2d(env->player.pos,
				vec2d_mul(vec2d_rotate(env->player.look, M_PI / 2), STEP));
	return (0);
}
