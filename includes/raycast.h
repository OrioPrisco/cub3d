/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:11:59 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/11/30 19:50:34 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_point	t_point;
typedef struct s_line	t_line;
typedef struct s_slope	t_slope;

bool	ray_line_intesect(t_point *out_point,
			const t_line *line, const t_line *ray);
int		ray_lines_intesect(t_point *out_point,
			const t_line *line, const t_line *ray, size_t n);
#endif
