/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/22 13:22:49 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	main(int ac, char **av)
{
	t_vector		cub;
	t_textures		textures;
	t_player_info	player;
	char			**map;

	ft_memset(&textures, 0, sizeof(t_textures));
	ft_bzero(&player, sizeof(t_player_info));
	exit_wrong_input(ac, av[1]);
	init_cub_vector(&cub, av[1]);
	if (!extract_colors(&cub, &textures, cub.size, -1))
		return (vector_free(&cub, &free_str), 1);
	if (!extract_textures(&cub, &textures, cub.size)
		||!find_player(&cub, &player))
		return (free_textures(&textures), vector_free(&cub, &free_str), 1);
	map = copy_vector(&cub, &player);
	if (!map)
		return (free_textures(&textures),
			vector_free(&cub, &free_str), 1);
	print_player(&cub, &player, 2);
	if (!flood_fill(map, &player))
		return (free_tab(map), vector_free(&cub, &free_str),
			free_textures(&textures), 1);
	print_map_copy((const char **)map, 2);
	return (free_tab(map), vector_free(&cub, &free_str),
		free_textures(&textures), 0);
}
