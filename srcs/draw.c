/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:20:04 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/01/10 23:23:10 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "raycast.h"
#include "math_utils.h"
#include "vector.h"
#include "draw.h"

//TODO : color using texture, ceiling and floor color
void	draw_column(t_column column, t_line ray,
			t_line look, const t_vector *lines)
{
	int		j;
	double	dist;
	double	draw_height;
	int		hit;
	t_point	point;

	j = 0;
	hit = ray_lines_intersect(&point, lines->data, ray, lines->size);
	dist = -1;
	if (hit >= 0)
	{
		dist = orth_distance(look, point);
		draw_height = column.image->height / dist;
	}
	while (j < column.image->height)
	{
		if (hit == -1
			|| j * 2 >= column.image->height + draw_height
			|| j * 2 <= column.image->height - draw_height)
			my_mlx_pixel_put(column.image, column.col, j, 0x00);
		else
			my_mlx_pixel_put(column.image, column.col, j,
				0xFF << ((hit % 5) * 4));
		j++;
	}
}
