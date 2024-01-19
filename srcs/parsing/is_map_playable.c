/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_playable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:19:48 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/19 15:15:27 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "math_utils.h"

char	**copy_vector(t_vector *cub, t_player_info *player)
{
	size_t	i;
	size_t	j;
	char	**map;

	i = -1;
	map = ft_calloc(player->max_x + 1, sizeof(char *));
	if (!map)
		return (NULL);
	while (++i < cub->size)
	{
		map[i] = ft_calloc(player->max_x + 1, sizeof(char *));
		if (!map[i])
			return (free_tab(map), NULL);
		j = -1;
		while (++j < ft_strlen(((char **)cub->data)[i]))
		{
			map[i][j] = ((char **)cub->data)[i][j];
		}
		while (j < player->max_x)
			map[i][j++] = ' ';
		map[i][j] = 0;
	}
	map[i] = 0;
	return (map);
}

static int	fill(char **map, t_point_size_t p, const t_player_info *player,
				const char to_fill)
{
	if (p.y < 0 || p.y >= player->max_y - 1 || p.x < 0 || p.x >= player->max_x
		|| map[p.y][p.x] != to_fill)
	{
		if (map[p.y][p.x] == 32)
		{
			printf("***la: y[%zu] x[%zu]\n", p.y, p.x);
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

int	flood_fill(char **map, t_player_info *player, t_vector *cub)
{
	t_point_size_t	p;

	player->max_y = cub->size;
	p.y = player->y;
	p.x = player->x;
	map[p.y][p.x] = '0';
	if (!fill(map, p, player, '0'))
		return (print_error(0, "Map contient espace.", "", 1));
	return (1);
}
