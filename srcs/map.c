/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:55:25 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/09 12:56:55 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	char_at_map(const t_map *map, int x, int y, char def)
{
	if (x < 0 || y < 0 || (size_t)x >= map->width || (size_t)y >= map->height)
		return (def);
	return (map->map[y][x]);
}
