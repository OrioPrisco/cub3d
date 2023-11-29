/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:52:33 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/11/29 15:28:05 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raycast.h"

t_slope	get_slope(const t_line *line)
{
	t_slope	slope;

	slope.m = fabs(line->start.y - line->end.y)
		/ fabs(line->start.x - line->end.x);
	slope.b = line->start.y;
	return (slope);
}

bool	ray_line_intesect(t_coord *out_point,
	const t_line *line, const t_line *ray)
{
	t_slope	slope_line;
	t_slope	slope_ray;
	t_coord	point;
	bool	intersec;

	slope_line = get_slope(line);
	slope_ray = get_slope(ray);
	if (slope_line.m == slope_ray.m)
		return (false);
	point.x = (slope_ray.b - slope_line.b)
		/ (slope_line.m - slope_ray.m);
	point.y = slope_ray.m * point.x + slope_ray.b;
	if (line->start.x < line->end.x)
		intersec = (point.x > line->start.x && point.x < line->end.x);
	else
		intersec = (point.x < line->start.x && point.x > line->end.x);
	if (intersec)
		*out_point = point;
	return (intersec);
}

/*

#include <stdio.h>

int main()
{
	t_line line = {{-1, 10}, {1, 10}};
	t_line ray = {{0,0}, {1, 0}};
	t_coord point = {-1,-1};
	bool foo;
	foo = ray_line_intesect(&point, &line, &ray);
	printf("intersec : %d\npoint : %lf;%lf\n", foo, point.x, point.y);
}
*/
