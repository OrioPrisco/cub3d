/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/09 17:30:13 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "math_utils.h"
#include <math.h>
#include "ft_printf.h"
#include <stdio.h>

#define WIDTH 210
#define HEIGHT 100

static const t_line	g_lines[] = {
{{-10, 10}, {10, 10}},
{{10, 10}, {10, -10}},
{{10, -10}, {-10, -10}},
{{-10, -10}, {-10, 10}},
};

static const size_t	g_num_lines = sizeof(g_lines) / sizeof(g_lines[0]);

static double	distance(const t_point *a, const t_point *b)
{
	return (sqrt(distance2(a, b)));
}

static void	draw_column(char screen[HEIGHT][WIDTH],
			const t_line *ray, const t_line *lines, int i)
{
	int		j;
	double	dist;
	int		hit;
	t_point	point;

	j = 0;
	hit = ray_lines_intersect(&point, lines, ray, g_num_lines);
	dist = -1;
	if (hit >= 0)
		dist = distance(&ray->start, &point) * 3;
	while (j < HEIGHT)
	{
		if (j <= dist || hit == -1)
			screen[j][i] = ' ';
		else
			screen[j][i] = hit + '0';
		j++;
	}
}

// TODO : do fov properly
//static const t_line	g_look = {{0, 0}, {0, 1}};
//const int		g_fov = 90;

int	main(void)
{
	char	screen[HEIGHT][WIDTH];
	size_t	i;
	t_line	ray;

	i = 0;
	while (i < WIDTH)
	{
		ray = (t_line){{0, 5}, {-10 + ((float)i * 20) / WIDTH, 6}};
		draw_column(&screen[0], &ray, &g_lines[0], i);
		i++;
	}
	i = 0;
	while (i < HEIGHT)
		printf("%.210s\n", screen[i++]);
}
