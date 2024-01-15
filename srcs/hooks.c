/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:09:40 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/15 15:52:27 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "hooks.h"
#include "draw.h"
#include "mlx.h"
#include <X11/X.h>
#include <stdlib.h>

//TODO : only draw after something changes
int	my_loop_hook(t_env *env)
{
	switch_frame(env);
	draw_screen(env->frame, &env->player, env);
	mlx_put_image_to_window(env->mlx, env->win, env->frame->img, 0, 0);
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
	mlx_expose_hook(env->win, my_expose, &env);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask, &quit_prg, &env);
	mlx_loop_hook(env->mlx, my_loop_hook, &env);
	mlx_hook(env->win, KeyPress, KeyPressMask, &deal_key, &env);
}
