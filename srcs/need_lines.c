/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:00:19 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/30 12:51:51 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"
#include "map.h"
#include "libft.h"

static bool	contains_zero_or_player(t_line line, const t_map *map, t_vec2d dir)
{
	t_point	point;

	point = line.start;
	while (point.y >= 0 && point.x >= 0
		&& point.x < map->width && point.y < map->height)
	{
		if (ft_strchr("0NSWE", map->map[(int)point.y][(int)point.x]))
			return (1);
		point = point_add_vec2d(point, dir);
	}
	return (0);
}

bool	need_line(t_line line, const t_map *map, t_vec2d dir, t_vec2d facing)
{
	t_line	line2;

	line2 = (t_line)
	{point_add_vec2d(line.start, facing), point_add_vec2d(line.end, facing)};
	if (contains_zero_or_player(line2, map, dir))
		return (1);
	return (0);
}
