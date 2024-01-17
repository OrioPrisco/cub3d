/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:38:23 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/17 16:33:46 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	find_player_utils(t_vector *cub, t_player_info *player)
{
	if (player->nb_player == 0)
		return (print_error(0, NO_PLAYER_FOUND, "", 1));
	if (player->nb_player > 1)
	{
		print_error(0, TOO_MANY_PLAYER, "", 1);
		return (ft_dprintf(2, "%d\n", player->nb_player), 0);
	}
	if (player->y == 0 || player->y == cub->size - 1
		|| player->x == 0 || player->x == player->x_line_len - 1)
		return (print_error(0, MAP_EDGE, "", 1));
	return (1);
}

int	find_player(t_vector *cub, t_player_info *player, size_t i, size_t j)
{
	while (++i < cub->size)
	{
		j = ft_strspn(((char **)cub->data)[i], " 01NSWE");
		if (j != ft_strlen(((char **)cub->data)[i]))
			return (print_error(0, INV_CHAR, &((char **)cub->data)[i][j], 3));
		j = -1;
		while (((char **)cub->data)[i][++j])
		{
			if (((char **)cub->data)[i][j] == 'N'
				|| ((char **)cub->data)[i][j] == 'S'
				|| ((char **)cub->data)[i][j] == 'W'
				|| ((char **)cub->data)[i][j] == 'E')
			{
				player->facing = ((char **)cub->data)[i][j];
				player->y = i;
				player->x = j;
				player->x_line_len = ft_strlen(((char **)cub->data)[i]);
				player->nb_player++;
			}
			if (j > player->max_x)
				player->max_x = j;
		}
	}
	return (find_player_utils(cub, player));
}
