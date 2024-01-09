/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:29:17 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/09 19:14:28 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "env.h"
#include "libft.h"
#include "mlx.h"

int	init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->frame = &env->frame1;
	if (!env->mlx)
		return (1);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!env->win)
		return (2);
	if (init_img(env, &env->frame1, WIDTH, HEIGHT)
		|| init_img(env, &env->frame2, WIDTH, HEIGHT))
		return (1);
	return (0);
}

void	switch_frame(t_env *env)
{
	if (env->frame == &env->frame1)
		env->frame = &env->frame2;
	else
		env->frame = &env->frame1;
}

void	destroy_env(t_env *env)
{
	if (!env->mlx)
		return ;
	if (env->frame1.img)
		mlx_destroy_image(env->mlx, env->frame1.img);
	if (env->frame2.img)
		mlx_destroy_image(env->mlx, env->frame2.img);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	return ;
}
