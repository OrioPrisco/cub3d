/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:31:32 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/30 12:51:20 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include "math_utils.h"
#include "map.h"

static size_t	ft_strspn_dir(const t_map *map, t_point point, t_vec2d dir,
					const char *str)
{
	size_t	span;

	span = 0;
	while (point.y >= 0 && point.x >= 0
		&& point.x < map->width && point.y < map->height)
	{
		if (!ft_strchr(str, map->map[(int)point.y][(int)point.x]))
			return (span);
		span++;
		point.x += dir.x;
		point.y += dir.y;
	}
	return (span);
}

typedef struct s_vectors {
	t_vector	*lines;
	t_vector	*textures;
}	t_vectors;

static bool	add_line(t_vectors out, t_vec2d offset,
				t_line line, size_t texture)
{
	line.start = point_add_vec2d(line.start, offset);
	line.end = point_add_vec2d(line.end, offset);
	if (vector_append(out.lines, &line))
		return (1);
	if (vector_append(out.textures, &texture))
		return (1);
	return (0);
}

typedef struct s_params {
	size_t	texture_id[2];
	t_vec2d	offset[2];
	t_vec2d	pointing[2];
	t_point	start_point;
	t_vec2d	dir;
}	t_params;

static bool	add_lines(const t_map *map, t_vectors out,
	t_line line, t_params params)
{
	if (need_line(line, map, params.dir, params.pointing[0]))
		if (add_line(out, params.offset[0], line, params.texture_id[0]))
			return (1);
	if (need_line(line, map, params.dir, params.pointing[1]))
		if (add_line(out, params.offset[1],
				(t_line){line.end, line.start}, params.texture_id[1]))
			return (1);
	return (0);
}

//if a line is like 
//"000111000"
// the line generated will be
//"000------"
static bool	map_to_lines_impl(const t_map *map, t_vector *lines,
				t_vector *textures, const t_params params)
{
	t_point	start;
	t_point	end;
	size_t	span;

	start = params.start_point;
	while (start.x >= 0 && start.y >= 0
		&& start.x < map->width && start.y < map->height)
	{
		start = point_add_vec2d(start, vec2d_mul(params.dir,
					ft_strspn_dir(map, start, params.dir, "NSWE0 ")));
		span = ft_strspn_dir(map, start, params.dir, " 1");
		if (!span)
			return (0);
		end = point_add_vec2d(start, vec2d_mul(params.dir, span));
		if (add_lines
			(map, (t_vectors){lines, textures}, (t_line){start, end}, params))
			return (1);
		start = end;
	}
	return (0);
}

static const t_params	g_params[] = {
{{0, 1}, {{0, 1}, {0, 0}}, {{0, 1}, {0, -1}}, {0, 0}, {1, 0}}, // N/S facing
{{3, 2}, {{0, 0}, {1, 0}}, {{-1, 0}, {1, 0}}, {0, 0}, {0, 1}}, // W/E facing
};

// assumes map is a rectangle
bool	map_to_lines(const t_map *map, t_vector *out_lines,
			t_vector *out_texture)
{
	t_params	params;
	size_t		i;

	params = g_params[0];
	i = 0;
	while (i < map->height)
	{
		params.start_point.y = i++;
		if (map_to_lines_impl(map, out_lines, out_texture, params))
			return (vector_clear(out_lines), vector_clear(out_texture), 1);
	}
	params = g_params[1];
	i = 0;
	while (i < map->width)
	{
		params.start_point.x = i++;
		if (map_to_lines_impl(map, out_lines, out_texture, params))
			return (vector_clear(out_lines), vector_clear(out_texture), 1);
	}
	return (0);
}
