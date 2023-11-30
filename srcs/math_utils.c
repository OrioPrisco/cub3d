/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:51:23 by OrioPrisco        #+#    #+#             */
/*   Updated: 2023/11/30 20:10:37 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"
#include <math.h>

double	distance2(const t_point *a, const t_point *b)
{
	double	x_diff;
	double	y_diff;

	x_diff = a->x - b->x;
	y_diff = a->y - b->y;
	return (x_diff * x_diff + y_diff * y_diff);
}

t_slope	get_slope(const t_line *line)
{
	t_slope	slope;

	slope.m = fabs(line->start.y - line->end.y)
		/ fabs(line->start.x - line->end.x);
	if (slope.m == -INFINITY)
		slope.m = INFINITY;
	slope.b = line->start.y - line->start.x * slope.m;
	return (slope);
}
