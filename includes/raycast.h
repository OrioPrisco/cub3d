/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:11:59 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/11/30 19:35:09 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_coord {
	double	x;
	double	y;
}	t_coord;

typedef struct s_line {
	t_coord	start;
	t_coord	end;
}	t_line;

// y = mx + b
typedef struct s_slope {
	double	m;
	double	b;
}	t_slope;

t_slope	get_slope(const t_line *line);
bool	ray_line_intesect(t_coord *out_point,
			const t_line *line, const t_line *ray);
int		ray_lines_intesect(t_coord *out_point,
			const t_line *line, const t_line *ray, size_t n);
#endif
