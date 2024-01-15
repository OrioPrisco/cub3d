/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:09:40 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/15 14:34:19 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "hooks.h"
#include "draw.h"
#include "mlx.h"
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
