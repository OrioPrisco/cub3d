/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:23:27 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/29 17:09:31 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "math_utils.h"
# include <stddef.h>

typedef struct s_vector	t_vector;

typedef struct s_map {
	char	**map;
	size_t	width;
	size_t	height;
}	t_map;

bool	map_to_lines(const t_map *map, t_vector *out_lines,
			t_vector *out_texture);
bool	need_line(t_line line, const t_map *map, t_vec2d dir, t_vec2d facing);

#endif
