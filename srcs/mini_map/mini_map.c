/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:36:45 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/30 13:05:08 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "image.h"
#include "map.h"
#include "mini_map.h"

static int	char_to_color(char c)
{
	if (c == '1')
		return (0xFF);
	if (c == '0')
		return (0xFFFFFF);
	if (c == ' ')
		return (0xFF);
	return (0xFF00);
}

static char	char_at_map(const t_map *map, int y, int x)
{
	if (x < 0 || y < 0 || (size_t)x >= map->width || (size_t)y >= map->height)
		return (' ');
	return (map->map[y][x]);
}

void	render_mini_map(t_img *mini,
			const t_map *map, const t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mini->height)
	{
		j = 0;
		while (j < mini->width)
		{
			my_mlx_pixel_put(mini, j, i, char_to_color(char_at_map(map,
						((float)i - mini->height / 2)
						/ mini->height * map->height + player->pos.y,
						((float)j - mini->width / 2)
						/ mini->width * map->width + player->pos.x)));
			j++;
		}
	}
}
