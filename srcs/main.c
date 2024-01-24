/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/24 12:57:39 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "vector.h"
#include "libft.h"
#include <stdlib.h>

static int	parse_cub(t_vector *cub, t_player_info *player,
				t_textures *textures)
{
	char	**map;

	map = 0;
	if (!extract_colors(cub, textures, cub->size, -1))
		return (vector_free(cub, &free_str), 0);
	if (!extract_textures(cub, textures, cub->size)
		||!find_player(cub, player))
		return (free_textures(textures), vector_free(cub, &free_str), 0);
	map = copy_vector(cub, player);
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
	t_player_info	player;

	ft_memset(&textures, 0, sizeof(t_textures));
	ft_bzero(&player, sizeof(t_player_info));
	exit_wrong_input(ac, av[1]);
	init_cub_vector(&cub, av[1]);
	if (!parse_cub(&cub, &player, &textures))
		exit(1);
	return (vector_free(&cub, &free_str),
		free_textures(&textures), 0);
}
