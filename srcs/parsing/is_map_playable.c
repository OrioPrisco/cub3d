/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_playable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:19:48 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/18 10:58:01 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**copy_vector(t_vector *cub, t_player_info *player)
{
	size_t	i;
	size_t	j;
	char	**map;

	i = -1;
	map = ft_calloc(cub->size + 1, sizeof(char *));
	if (!map)
		return (NULL);
	while (++i < cub->size)
	{
		map[i] = ft_calloc(player->max_x + 1, sizeof(char *));
		if (!map[i])
			return (free_tab(map), NULL);
		j = -1;
		while (++j < ft_strlen(((char **)cub->data)[i]))
			map[i][j] = ((char **)cub->data)[i][j];
		while (j < player->max_x)
			map[i][j++] = 'Z';
		map[i][j] = 0;
	}
	map[i] = 0;
	return (map);
}
