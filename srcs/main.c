/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/30 13:01:47 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "vector.h"
#include "libft.h"
#include <stdlib.h>
#include "utils.h"
#include "env.h"
#include "raycast.h"
#include "hooks.h"
#include "mlx.h"

static int	parse_cub(t_vector *cub, t_player_info *player,
				t_textures *textures)
{
	char	**map;

	map = 0;
	if (!extract_colors(cub, textures))
		return (vector_free(cub, &free_str), 0);
	if (!extract_textures(cub, textures, cub->size)
		||!find_player(cub, player))
		return (free_textures(textures), vector_free(cub, &free_str), 0);
	map = vector_to_2dtab(cub, player->max_x);
	if (!map)
		return (free_textures(textures),
			vector_free(cub, &free_str), 0);
	if (!flood_fill(map, player))
		return (free_tab(map), vector_free(cub, &free_str),
			free_textures(textures), 0);
	free_tab(map);
	return (1);
}

int	main(int ac, char **av)
{
	t_vector		cub;
	t_textures		textures;
	t_env			env;
	t_player_info	p_info;

	ft_memset(&textures, 0, sizeof(t_textures));
	ft_bzero(&env, sizeof(env));
	ft_bzero(&p_info, sizeof(p_info));
	exit_wrong_input(ac, av[1]);
	init_cub_vector(&cub, av[1]);
	if (!parse_cub(&cub, &p_info, &textures))
		exit(1);
	calculate_angles(WIDTH, env.angles, 90, 1);
	if (init_env(&env)
		|| load_into_env(&env, &cub, &textures, &p_info))
		return (vector_free(&cub, &free_str),
			free_textures(&textures), destroy_env(&env), 1);
	vector_free(&cub, &free_str);
	free_textures(&textures);
	register_hooks(&env);
	mlx_loop(env.mlx);
}
