/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:38:23 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/22 13:08:31 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	find_player_utils(const t_vector *c, t_player_info *player)
{
	if (player->nb_player == 0)
		return (print_error(0, NO_PLAYER_FOUND, "", 1));
	if (player->nb_player > 1)
	{
		print_error(0, TOO_MANY_PLAYER, "", 1);
		return (ft_dprintf(2, "%d\n", player->nb_player), 0);
	}
	if (player->y == 0 || player->y == c->size - 1
		|| player->x == 0)
		return (print_error(0, MAP_EDGE, "", 1));
	return (1);
}

static void	find_player_utils_update(const t_vector *c,
				t_player_info *player, size_t i, size_t j)
{
	player->facing = ((char **)c->data)[i][j];
	player->y = i;
	player->x = j;
	player->nb_player++;
}

int	find_player(const t_vector *c, t_player_info *player)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < c->size)
	{
		j = ft_strspn(((char **)c->data)[i], " 01NSWE");
		if (j != ft_strlen(((char **)c->data)[i]))
			return (print_error(0, INV_CHAR, &((char **)c->data)[i][j], 3));
		j = -1;
		while (((char **)c->data)[i][++j])
		{
			if (((char **)c->data)[i][j] == 'N'
				|| ((char **)c->data)[i][j] == 'S'
				|| ((char **)c->data)[i][j] == 'W'
				|| ((char **)c->data)[i][j] == 'E')
				find_player_utils_update(c, player, i, j);
			player->x_line_len = ft_strlen(((char **)c->data)[i]);
			if (player->x == player->x_line_len - 1)
				return (print_error(0, MAP_EDGE, "", 1));
			if (player->x_line_len > player->max_x)
				player->max_x = player->x_line_len;
		}
	}
	return (find_player_utils(c, player));
}
