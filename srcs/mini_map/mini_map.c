/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:36:45 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/30 10:19:07 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "image.h"

int	char_to_color(char c)
{
	if (c == '1')
		return (0xFF);
	if (c == '0')
		return (0xFFFFFF);
	if (c == ' ')
		return (0xFF);
	return (0xFF00);
}

char	char_at_map(char **map, const t_player_info *info, int y, int x)
{
	if (x < 0 || y < 0 || (size_t)x >= info->max_x || (size_t)y >= info->max_y)
		return (' ');
	return (map[y][x]);
}

void	render_mini_map(t_player_info *p_info, t_img *mini,
			char **map, const t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mini->height)
	{
		j = 0;
		while (j < mini->width)
		{
			my_mlx_pixel_put(mini, j, i, char_to_color(char_at_map(map, p_info,
						((float)i - mini->height / 2)
						/ mini->height * p_info->max_y + player->pos.y,
						((float)j - mini->width / 2)
						/ mini->width * p_info->max_x + player->pos.x)));
			j++;
		}
	}
}
