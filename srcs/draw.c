/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:20:04 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/02/08 17:31:25 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "raycast.h"
#include "math_utils.h"
#include "vector.h"
#include "draw.h"
#include "env.h"
#include <math.h>

typedef struct s_bs {
	int		hit;
	double	text_x;
}	t_bs;

static void	draw_texture(t_column column, double draw_height,
		const t_graphics *graphics, t_bs bs)
{
	int			j;
	double		text_y;
	const t_img	*texture;
	size_t		text_index;

	if (bs.hit == -1)
		return ;
	text_index = ((size_t *)graphics->line_textures_id.data)[bs.hit];
	texture = &((t_img *)graphics->textures.data)[text_index];
	text_y = fmax(0, draw_height - column.image->height)
		* (texture->height / (draw_height * 2));
	j = 0;
	while (j < column.image->height)
	{
		if (!(j * 2 >= column.image->height + draw_height
				|| j * 2 <= column.image->height - draw_height))
		{
			my_mlx_pixel_put(column.image, column.col, j,
				get_pixel(texture, bs.text_x, text_y));
			text_y += texture->height / draw_height;
		}
		j++;
	}
}

typedef struct s_bs2 {
	t_line	ray;
	t_line	look;
}	t_bs2;

static void	draw_column(t_column column, t_bs2 bs2, const t_vector *lines,
			const t_graphics *graphics)
{
	double	dist;
	double	draw_height;
	int		hit;
	t_point	point;
	double	text_x;

	hit = ray_lines_intersect(&point, lines->data, bs2.ray, lines->size);
	dist = -1;
	text_x = 0;
	draw_height = 0;
	if (hit >= 0)
	{
		dist = orth_distance(bs2.look, point);
		draw_height = column.image->height / dist;
		text_x = fmod
			(sqrt(distance2(((t_line *)lines->data)[hit].start, point)), 1)
			* ((t_img *)graphics->textures.data)
		[((size_t *)graphics->line_textures_id.data)[hit]].width;
	}
	draw_texture(column, draw_height, graphics, (t_bs){hit, text_x});
}

static void	draw_skybox(t_img *image, int ceil_col, int floor_col)
{
	int	i;
	int	col;

	i = 0;
	while (i < image->height)
	{
		if (i * 2 > image->height)
			col = ceil_col;
		else
			col = floor_col;
		img_put_graph_line(image, (t_graph_line){0, i, image->width, col});
		i++;
	}
}

void	draw_screen(t_img *image, const t_player *player,
			const t_env *env)
{
	int		i;
	t_vec2d	ray_vec;
	t_line	ray;
	t_line	player_look;

	i = 0;
	player_look = (t_line)
	{player->pos, point_add_vec2d(player->pos, player->look)};
	draw_skybox(image, env->graphics.ceil_col, env->graphics.floor_col);
	while (i < image->width)
	{
		ray_vec = vec2d_rotate(player->look, env->angles[i]);
		ray = (t_line){player->pos, point_add_vec2d(player->pos, ray_vec)};
		draw_column((t_column)
		{image, i}, (t_bs2){ray, player_look}, &env->lines, &env->graphics);
		i++;
	}
}
