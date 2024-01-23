/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/26 12:43:05 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "math_utils.h"
#include "libft.h"
#include "env.h"
#include "mlx.h"
#include "draw.h"
#include "hooks.h"
#include <X11/X.h>
#include "map.h"
#include <stdlib.h>

//#define WIDTH 210
//#define HEIGHT 100

/*
static const t_line	g_lines[] = {
{{-11, 10}, {11, 10}},
{{10, 11}, {10, -11}},
{{11, -10}, {-11, -10}},
{{-10, -11}, {-10, 11}},
{{-9, 9}, {-5, 9}},
{{9, 9}, {9, 8}},
{{9, -9}, {-8, -9}},
{{-9, -9}, {-9, -8}},
{{0, 0}, {11, 11}},
};

static const size_t	g_num_lines = sizeof(g_lines) / sizeof(g_lines[0]);

static const size_t	g_texture_id[] = {
	0,
	1,
	0,
	1,
	0,
	1,
	0,
	1,
	1.
};
*/

static char	*g_tab[] = {
	"111111111",
	"100000001",
	"101111001",
	"100001001",
	"100000001",
	"111111111",
	NULL
};

int	main(void)
{
	t_env		env;
	t_img		tmp;

	ft_bzero(&env, sizeof(env));
	init_env(&env);
	//vector_copy_n(&env.lines, g_lines, g_num_lines, sizeof(g_lines[0]));
	load_xpm(env.mlx, "textures/ball.xpm", &tmp);
	vector_append(&env.graphics.textures, &tmp);
	load_xpm(env.mlx, "textures/test.xpm", &tmp);
	vector_append(&env.graphics.textures, &tmp);
	load_xpm(env.mlx, "textures/brick_wall.xpm", &tmp);
	vector_append(&env.graphics.textures, &tmp);
	load_xpm(env.mlx, "textures/test.xpm", &tmp);
	vector_append(&env.graphics.textures, &tmp);
	//vector_copy_n(&env.graphics.line_textures_id, g_texture_id, g_num_lines, sizeof(g_texture_id[0]));
	if (map_to_lines(g_tab, &env.lines, &env.graphics.line_textures_id, (t_point){9,6}))
		exit(100);
	env.player.look.x = 1;
	env.bonus = false;//true;
	env.graphics.ceil_col = 0xFF;
	env.graphics.floor_col = 0xFF00;
	calculate_angles(WIDTH, env.angles, 90, 1);
	register_hooks(&env);
	mlx_loop(env.mlx);
}
