/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/09 19:15:00 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "math_utils.h"
#include <math.h>
#include "ft_printf.h"
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include "env.h"
#include "mlx.h"

//#define WIDTH 210
//#define HEIGHT 100

static const t_line	g_lines[] = {
{{-10, 10}, {10, 10}},
{{10, 10}, {10, -10}},
{{10, -10}, {-10, -10}},
{{-10, -10}, {-10, 10}},
{{-9, 9}, {-5, 9}},
{{9, 9}, {9, 8}},
{{9, -9}, {-8, -9}},
{{-9, -9}, {-9, -8}},
};

static const size_t	g_num_lines = sizeof(g_lines) / sizeof(g_lines[0]);

static t_line		g_look = {{-8, 0}, {-7, 0}};

static void	draw_column(t_env *env,
			const t_line *ray, const t_line *lines, int i)
{
	int		j;
	double	dist;
	double	draw_height;
	int		hit;
	t_point	point;

	j = 0;
	hit = ray_lines_intersect(&point, lines, ray, g_num_lines);
	draw_height = 0;
	dist = -1;
	if (hit >= 0)
	{
		dist = orth_distance(&g_look, &point);
		draw_height = HEIGHT / dist;
	}
	while (j < HEIGHT)
	{
		if (j >= HEIGHT / 2 + draw_height / 2
			|| j <= HEIGHT / 2 - draw_height / 2
			|| hit == -1)
			my_mlx_pixel_put(env->frame, i, j, 0x00);
		else
			my_mlx_pixel_put(env->frame, i, j, 0xFF << ((hit % 5) * 4));
		j++;
	}
}

int	main(void)
{
	size_t	i;
	t_line	ray;
	t_vec2d	look_vec;
	t_vec2d	ray_vec;
	double	angles[WIDTH];
	t_env	env;

	ft_bzero(&env, sizeof(env));
	init_env(&env);
	calculate_angles(WIDTH, angles, 90, 1);
	i = 0;
	char *input = get_next_line(0);
	while (input)
	{
		if (!ft_strcmp(input, "d\n"))
		{
			t_vec2d	vec = {g_look.end.x - g_look.start.x, g_look.end.y - g_look.start.y};
			vec = vec2d_rotate(&vec, M_PI/30);
			g_look.end = (t_point){g_look.start.x + vec.x, g_look.start.y + vec.y};
		}
		if (!ft_strcmp(input, "a\n"))
		{
			t_vec2d	vec = {g_look.end.x - g_look.start.x, g_look.end.y - g_look.start.y};
			vec = vec2d_rotate(&vec, -M_PI/30);
			g_look.end = (t_point){g_look.start.x + vec.x, g_look.start.y + vec.y};
		}
		if (!ft_strcmp(input, "w\n"))
		{
			t_vec2d	vec = {g_look.end.x - g_look.start.x, g_look.end.y - g_look.start.y};
			g_look = (t_line){
			{g_look.start.x + vec.x, g_look.start.y + vec.y},
			{g_look.end.x + vec.x, g_look.end.y + vec.y}};
		}
		if (!ft_strcmp(input, "s\n"))
		{
			t_vec2d	vec = {g_look.end.x - g_look.start.x, g_look.end.y - g_look.start.y};
			g_look = (t_line){
			{g_look.start.x - vec.x, g_look.start.y - vec.y},
			{g_look.end.x - vec.x, g_look.end.y - vec.y}};
		}
		i = 0;
		look_vec = (t_vec2d){g_look.end.x - g_look.start.x, g_look.end.y - g_look.start.y};
		while (i < WIDTH)
		{
			ray_vec = vec2d_rotate(&look_vec, angles[i]);
			ray = (t_line){g_look.start, {g_look.start.x + ray_vec.x, g_look.start.y + ray_vec.y}};
			draw_column(&env, &ray, &g_lines[0], i);
			i++;
		}
		mlx_put_image_to_window(env.mlx, env.win, env.frame->img, 0, 0);
		input = get_next_line(0);
	}
}
