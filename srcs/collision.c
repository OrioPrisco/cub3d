/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:03:44 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/23 17:52:21 by OrioPrisc        ###   ########.fr       */
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
	line_vec = (t_vec2d){line.end.x - line.start.x, line.end.y - line.start.y};
	line_vec = vec2d_mul(vec2d_to_unit(line_vec), len);
	projected = point_add_vec2d(line.start, line_vec);
	correction_vec = (t_vec2d){projected.x - point.x, projected.y - point.y};
	correction_vec = vec2d_mul(vec2d_to_unit(correction_vec),
			sqrt(vec2d_len2(correction_vec)) + STEP / 10);
	return (point_add_vec2d(point, correction_vec));
}

// orth project the end of the vector onto the hit surface
// and try again
void	move_player(t_player *player, const t_vector *lines, bool bonus,
			t_vec2d vec)
{
	t_point	collision;
	t_line	ray;
	int		hit;
	t_point	projected;
	t_vec2d	corrected;

	if (!(vec.x || vec.y))
		return ;
	ray = (t_line){player->pos, point_add_vec2d(player->pos, vec)};
	hit = ray_lines_intersect(&collision, lines->data, ray, lines->size);
	if (hit != -1 && bonus)
	{
		if (is_between(collision.x, ray.start.x, ray.end.x)
			&& is_between(collision.y, ray.start.y, ray.end.y))
		{
			projected = orth_correct(((t_line *)lines->data)[hit],
					point_add_vec2d(player->pos, vec));
			corrected = (t_vec2d)
			{projected.x - player->pos.x, projected.y - player->pos.y};
			return (move_player(player, lines, bonus, corrected));
		}
	}
	player->pos = point_add_vec2d(player->pos, vec);
}
