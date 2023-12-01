/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:52:33 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/11/30 23:02:09 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raycast.h"
#include "math_utils.h"

// returns the intersection points between a perpendicular line
// and a regular line
static t_point	line_line_intersect_perpendicular(
			const t_line *perpendicular, const t_slope *slope)
{
	return ((t_point){perpendicular->start.x,
		slope->m * perpendicular->start.x + slope->b});
}

bool	ray_line_intesect(t_point *out_point,
	const t_line *line, const t_line *ray)
{
	t_slope	slope_line;
	t_slope	slope_ray;
	t_point	point;
	bool	intersec;

	slope_line = get_slope(line);
	slope_ray = get_slope(ray);
	if (slope_line.m == slope_ray.m)
		return (false);
	point.x = (slope_ray.b - slope_line.b)
		/ (slope_line.m - slope_ray.m);
	point.y = slope_ray.m * point.x + slope_ray.b;
	if (slope_line.m == INFINITY)
		point = line_line_intersect_perpendicular(line, &slope_ray);
	if (slope_ray.m == INFINITY)
		point = line_line_intersect_perpendicular(ray, &slope_line);
	intersec = is_between(point.x, line->start.x, line->end.x)
		&& is_between(point.y, line->start.y, line->end.y);
	if (intersec)
		*out_point = point;
	return (intersec);
}

//returns index of line (-1 for none) and the intersection point
int	ray_lines_intesect(t_point *out_point,
	const t_line *line, const t_line *ray, size_t n)
{
	t_point	best;
	t_point	current;
	int		best_index;
	size_t	i;

	best = (t_point){INFINITY, INFINITY};
	best_index = -1;
	i = 0;
	while (i < n)
	{
		if (ray_line_intesect(&current, line + i, ray))
		{
			if (distance2(&ray->start, &current)
				< distance2(&ray->start, &best))
			{
				best = current;
				best_index = i;
			}
		}
		i++;
	}
	if (best_index >= 0)
		*out_point = best;
	return (best_index);
}

/*

#include <stdio.h>

int main()
{
	t_line lines[] = {
		{{-1, 10}, {1, 10}},
		{{-2,10}, {-1,10}},
		{{-10,4},{10, 5}},
		{{10,-10},{10,10}}
	};
	t_line ray = {{0,0}, {1, 1}};
	t_point point = {-1,-1};
	int foo;
	foo=ray_lines_intesect(&point, &lines[0], &ray, sizeof(lines)/sizeof(lines[0]));
	printf("intersec : %d\npoint : %lf;%lf\n", foo, point.x, point.y);
}
*/
