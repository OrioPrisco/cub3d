/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:38:23 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/26 16:00:52 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "messages.h"
#include "ft_printf.h"
#include "vector.h"
#include "libft.h"

static int	find_player_utils(const t_vector *c,
				t_player_info *player, size_t nb_player)
{
	if (nb_player == 0)
		return (print_error(0, NO_PLAYER_FOUND, "", 1));
	if (nb_player > 1)
	{
		print_error(0, TOO_MANY_PLAYER, "", 1);
		return (ft_dprintf(2, "%d\n", nb_player), 0);
	}
	if (player->y == 0 || player->y == c->size - 1
		|| player->x == 0)
		return (print_error(0, MAP_EDGE, "", 1));
	player->max_y = c->size;
	return (1);
}

static void	find_player_utils_update(const t_vector *c,
				t_player_info *player, size_t i, size_t j)
{
	player->facing = ((char **)c->data)[i][j];
	player->y = i;
	player->x = j;
}

int	find_player(const t_vector *c, t_player_info *player)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	nb_player;

	i = -1;
	nb_player = 0;
	while (++i < c->size)
	{
		j = -1;
		while (((char **)c->data)[i][++j])
		{
			if (!ft_strchr("NSWE01 ", ((char **)c->data)[i][j]))
				return (print_error(0, INV_CHAR, &((char **)c->data)[i][j], 3));
			if (ft_strchr("NSWE", ((char **)c->data)[i][j]))
				(find_player_utils_update(c, player, i, j), nb_player++);
			len = ft_strlen(((char **)c->data)[i]);
			if (player->x + 1 == len)
				return (print_error(0, MAP_EDGE, "", 1));
			if (len > player->max_x)
				player->max_x = len;
		}
	}
	return (find_player_utils(c, player, nb_player));
}
