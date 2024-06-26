/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_lines_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:33:01 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/12 14:36:18 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"
#include "map.h"
#include "libft.h"
#include "vector.h"
#include "env.h"

typedef bool			t_adder(const t_map*, t_graphics*, t_vector*, t_point);

typedef struct s_params {
	char		check;
	t_adder		*add_fct;
}	t_params;

bool	add_door(const t_map *map, t_graphics *graphics_out,
		t_vector *lines_out, t_point point)
{
	t_line	door;

	door = (t_line){{point.x, point.y + .5}, {point.x + 1, point.y + .5}};
	if (char_at_map(map, point.x, point.y - 1, ' ') == '1'
		&& char_at_map(map, point.x, point.y + 1, ' ') == '1')
		door = (t_line){{point.x + .5, point.y}, {point.x + .5, point.y + 1}};
	return (0
		|| vector_append(&graphics_out->doors,
			&(t_door){lines_out->size, 0, 0, 0})
		|| vector_append(lines_out, &door)
		|| vector_append(&graphics_out->line_textures_id, &(size_t){4})
		);
}

bool	add_sprite(const t_map *map, t_graphics *graphics_out,
		t_vector *lines_out, t_point point)
{
	t_line		line;
	t_sprite	sprite;

	line = (t_line){{point.x, point.y + .5}, {point.x + 1, point.y + .5}};
	sprite = (t_sprite){lines_out->size, {point.x + .5, point.y + .5}};
	(void)map;
	return (vector_append(&graphics_out->sprites, &sprite)
		|| vector_append(lines_out, &line)
		|| vector_append(&graphics_out->line_textures_id, &(size_t){5}));
}

static const t_params	g_params[] = {
{'D', add_door}, // Door
{'B', add_sprite}, // Sprite
};

static bool	map_to_bonus_impl(const t_map *map, t_graphics *graphics_out,
				t_vector *lines_out,
				const t_params params)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == params.check)
				if (params.add_fct
					(map, graphics_out, lines_out, (t_point){x, y}))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

bool	map_to_bonus(const t_map *map, t_graphics *graphics_out,
			t_vector *lines_out, size_t	*solid_lines)
{
	if (map_to_bonus_impl(map, graphics_out, lines_out, g_params[0]))
		return (1);
	*solid_lines = lines_out->size;
	if (map_to_bonus_impl(map, graphics_out, lines_out, g_params[1]))
		return (1);
	return (0);
}
