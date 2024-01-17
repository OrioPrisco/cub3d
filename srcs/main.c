/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/17 16:34:37 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	main(int ac, char **av)
{
	t_vector		cub;
	t_textures		textures;
	t_player_info	player;

	ft_bzero(&player, sizeof(t_player_info));
	ft_memset(&textures, 0, sizeof(t_textures));
	exit_wrong_input(ac, av[1]);
	init_cub_vector(&cub, av[1]);
	if (!extract_colors(&cub, &textures, cub.size, -1))
		return (vector_free(&cub, &free_str), 1);
	if (!extract_textures(&cub, &textures, cub.size))
	{
		free_textures(&textures);
		return (vector_free(&cub, &free_str), 1);
	}
	find_player(&cub, &player, -1, 0);
	print_player(&cub, &player, 2);
	vector_free(&cub, &free_str);
	free_textures(&textures);
	return (0);
}
