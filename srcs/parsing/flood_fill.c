/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:19:48 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/29 13:41:33 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "vector.h"
#include "messages.h"
#include "ft_printf.h"
#include "utils.h"

typedef struct t_szt_point
{
	long	x;
	long	y;
}	t_point_size_t;

static int	fill(char **map, t_point_size_t p, const t_player_info *player,
				const char to_fill)
{
	if (p.y < 0 || p.y >= (long)player->max_y || p.x < 0
		|| p.x >= (long)player->max_x)
		return (1);
	if (map[p.y][p.x] != to_fill)
	{
		if (map[p.y][p.x] == 32)
		{
			print_error(0, NO_WALL, "", 2);
			ft_dprintf(2, "Y:[%d] X:[%d]\n", p.y, p.x);
			return (0);
		}
		return (1);
	}
	map[p.y][p.x] = player->facing;
	if (!fill(map, (t_point_size_t){p.x - 1, p.y}, player, to_fill))
		return (0);
	if (!fill(map, (t_point_size_t){p.x + 1, p.y}, player, to_fill))
		return (0);
	if (!fill(map, (t_point_size_t){p.x, p.y - 1}, player, to_fill))
		return (0);
	if (!fill(map, (t_point_size_t){p.x, p.y + 1}, player, to_fill))
		return (0);
	return (1);
}

int	flood_fill(char **map, const t_player_info *player)
{
	t_point_size_t	p;

	p.y = player->y;
	p.x = player->x;
	map[p.y][p.x] = '0';
	if (!fill(map, p, player, '0'))
		return (0);
	return (1);
}
