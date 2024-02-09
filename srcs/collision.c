/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:03:44 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/09 12:53:35 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "raycast.h"
#include "collision.h"
#include <math.h>

// projects the point on the line, slightly outward by STEP/10
t_point	orth_correct(t_line line, t_point point)
{
	double	len;
	t_point	projected;
	t_vec2d	line_vec;
	t_vec2d	correction_vec;

	len = orth_distance(line, point);
	line_vec = vec2d_to(line.start, line.end);
	line_vec = vec2d_mul(vec2d_to_unit(line_vec), len);
	projected = point_add_vec2d(line.start, line_vec);
	correction_vec = vec2d_to(point, projected);
	correction_vec = vec2d_mul(vec2d_to_unit(correction_vec),
			sqrt(vec2d_len2(correction_vec)) + STEP / 10);
	return (point_add_vec2d(point, correction_vec));
}

// orth project the end of the vector onto the hit surface
// and try again
t_vec2d	move_player(t_player *player, const t_vector *lines, bool bonus,
			t_vec2d vec)
{
	t_point	collision;
	t_line	ray;
	int		hit;
	t_point	projected;
	t_vec2d	corrected;

	if (!(vec.x || vec.y))
		return ((t_vec2d){0, 0});
	ray = (t_line){player->pos, point_add_vec2d(player->pos, vec)};
	hit = ray_lines_intersect(&collision, lines->data, ray, lines->size);
	if (hit != -1 && bonus)
	{
		if (is_between(collision.x, ray.start.x, ray.end.x)
			&& is_between(collision.y, ray.start.y, ray.end.y))
		{
			projected = orth_correct(((t_line *)lines->data)[hit],
					point_add_vec2d(player->pos, vec));
			corrected = vec2d_to(player->pos, projected);
			return (move_player(player, lines, bonus, corrected));
		}
	}
	return (vec);
}
