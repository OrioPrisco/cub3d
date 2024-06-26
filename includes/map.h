/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:23:27 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/12 13:12:04 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "math_utils.h"
# include <stddef.h>

typedef struct s_vector		t_vector;
typedef struct s_graphics	t_graphics;
typedef struct s_env		t_env;

typedef struct s_map {
	char	**map;
	size_t	width;
	size_t	height;
}	t_map;

bool	map_to_lines(const t_map *map, t_env *out, bool bonus);
bool	map_to_bonus(const t_map *map, t_graphics *g_out, t_vector *lines_out,
			size_t *solid_lines);
bool	need_line(t_line line, const t_map *map, t_vec2d dir, t_vec2d facing);
char	char_at_map(const t_map *map, int x, int y, char def);

#endif
