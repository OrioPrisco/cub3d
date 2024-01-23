/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:23:27 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/23 14:21:47 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "math_utils.h"

typedef struct s_vector	t_vector;

bool	map_to_lines(char **map, t_vector *out_lines, t_vector *out_texture,
			t_point size);
bool	need_line(t_line line, char **map, t_vec2d dir, t_vec2d facing);

#endif
