/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:11:59 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/10 23:22:26 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_point	t_point;
typedef struct s_line	t_line;
typedef struct s_slope	t_slope;

bool	ray_line_intersect(t_point *out_point, t_line line, t_line ray);
int		ray_lines_intersect(t_point *out_point,
			const t_line *line, t_line ray, size_t n);
void	calculate_angles(size_t width, double angles[width],
			double fov, double plane_dist);
#endif
