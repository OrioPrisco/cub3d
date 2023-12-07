/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:51:23 by OrioPrisco        #+#    #+#             */
/*   Updated: 2023/12/07 18:54:30 by OrioPrisco       ###   ########.fr       */
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

// projects the point on the given line and calculates it's distance
// to line.start
double	orth_distance(const t_line *line, const t_point *point)
{
	t_vec2d	line_vec;
	t_vec2d	point_vec;
	double	dot_product;
	double	result;

	line_vec = (t_point)
	{line->end.x - line->start.x, line->end.y - line->start.y};
	point_vec = (t_point){point->x - line->start.x, point->y - line->start.y};
	dot_product = line_vec.x * point_vec.x + line_vec.y * point_vec.y;
	result = dot_product / sqrt(distance2(&line->start, &line->end));
	return (result);
}

t_slope	get_slope(const t_line *line)
{
	t_slope	slope;

	slope.m = (line->start.y - line->end.y)
		/ (line->start.x - line->end.x);
	if (slope.m == -INFINITY)
		slope.m = INFINITY;
	slope.b = line->start.y - line->start.x * slope.m;
	return (slope);
}

static const double	g_epsilon = 0.001;

bool	less_than(double a, double b)
{
	return ((a - b) <= g_epsilon);
}

bool	is_between(double value, double bound1, double bound2)
{
	if (bound1 < bound2)
		return (less_than(bound1, value) && less_than(value, bound2));
	else
		return (less_than(bound2, value) && less_than(value, bound1));
}
