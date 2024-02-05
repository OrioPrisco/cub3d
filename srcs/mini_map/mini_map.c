/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:36:45 by mpeulet           #+#    #+#             */
/*   Updated: 2024/02/05 11:08:01 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "image.h"
#include "map.h"
#include "mini_map.h"
#include <math.h>

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
			const t_map *map, const t_player *player, double blocks)
{
	int		i;
	int		j;
	t_vec2d	rotated;
	double	angle;

	i = -1;
	angle = atan2(player->look.x, -player->look.y);
	while (++i < mini->height)
	{
		j = 0;
		while (j < mini->width)
		{
			rotated = vec2d_rotate((t_vec2d){
					(((double)j) / mini->width - .5) * blocks,
					(((double)i) / mini->height - .5) * blocks
					* mini->height / mini->width}, angle);
			my_mlx_pixel_put(mini, j, i, char_to_color(char_at_map(map,
						rotated.y + player->pos.y,
						rotated.x + player->pos.x
						)));
			j++;
		}
	}
}
