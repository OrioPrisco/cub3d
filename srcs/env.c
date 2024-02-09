/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:29:17 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/09 15:16:10 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "libft.h"
#include "mlx.h"
#include "map.h"
#include "parsing.h"
#include "vector.h"
#include "utils.h"
#include "messages.h"

int	init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->frame = &env->frame1;
	vector_init(&env->lines, sizeof(t_line));
	vector_init(&env->graphics.textures, sizeof(t_img));
	vector_init(&env->graphics.line_textures_id, sizeof(size_t));
	vector_init(&env->graphics.doors, sizeof(t_door));
	vector_init(&env->graphics.sprites_id, sizeof(size_t));
	if (!env->mlx)
		return (print_error(1, MLX_PB, "", 1));
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!env->win)
		return (print_error(1, MLX_PB, "", 1));
	if (init_img(env, &env->frame1, WIDTH, HEIGHT)
		|| init_img(env, &env->frame2, WIDTH, HEIGHT)
		|| init_img(env, &env->mini_map, WIDTH / 10, HEIGHT / 10))
		return (print_error(1, MLX_PB, "", 1));
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
	size_t	i;
	t_img	*image;

	vector_clear(&env->lines);
	vector_clear(&env->graphics.line_textures_id);
	vector_clear(&env->graphics.doors);
	vector_clear(&env->graphics.sprites_id);
	free_tab(env->map.map);
	if (!env->mlx)
		return ;
	destroy_img(env->mlx, &env->frame1);
	destroy_img(env->mlx, &env->frame2);
	destroy_img(env->mlx, &env->mini_map);
	i = 0;
	while (i < env->graphics.textures.size)
	{
		image = ((t_img *)env->graphics.textures.data) + i++;
		mlx_destroy_image(env->mlx, image->img);
	}
	vector_clear(&env->graphics.textures);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
}

bool	load_into_env(t_env *env, const t_vector *cub,
			const t_textures *textures, const t_player_info *player_info)
{
	char	**map_copy;

	env->player.pos = (t_point){player_info->x + 0.5, player_info->y + 0.5};
	if (player_info->facing == 'N')
		env->player.look = (t_vec2d){0, -1};
	if (player_info->facing == 'S')
		env->player.look = (t_vec2d){0, 1};
	if (player_info->facing == 'W')
		env->player.look = (t_vec2d){-1, 0};
	if (player_info->facing == 'E')
		env->player.look = (t_vec2d){1, 0};
	env->graphics.floor_col = textures->colors[0];
	env->graphics.ceil_col = textures->colors[1];
	if (load_textures(&env->graphics.textures, textures, env->mlx, env->bonus))
		return (print_error(1, MLX_PB, "while loading textures", 2));
	map_copy = vector_to_2dtab(cub, player_info->max_x);
	if (!map_copy)
		return (print_error(1, MALLOC_FAIL, "copying map.", 2));
	if (map_to_lines(&(t_map){map_copy, player_info->max_x, player_info->max_y},
		&env->lines, &env->graphics, env->bonus))
		return (free_tab(map_copy),
			print_error(1, MALLOC_FAIL, "allocating map to line vector", 1));
	env->map = (t_map){map_copy, player_info->max_x, player_info->max_y};
	return (0);
}
