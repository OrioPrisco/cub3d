/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:11:59 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/11/30 19:37:50 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_point {
	double	x;
	double	y;
}	t_point;

typedef struct s_line {
	t_point	start;
	t_point	end;
}	t_line;

// y = mx + b
typedef struct s_slope {
	double	m;
	double	b;
}	t_slope;

t_slope	get_slope(const t_line *line);
bool	ray_line_intesect(t_point *out_point,
			const t_line *line, const t_line *ray);
int		ray_lines_intesect(t_point *out_point,
			const t_line *line, const t_line *ray, size_t n);
#endif
