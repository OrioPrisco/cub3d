/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:33:21 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/12 17:02:13 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define WIDTH 800
# define HEIGHT 1200
# include "vector.h"
# include "image.h"
# include <stdbool.h>
# include "math_utils.h"

typedef struct s_graphics {
	t_vector	textures;
	t_vector	line_textures_id;
	int			ceil_col;
	int			floor_col;
}	t_graphics;

typedef struct s_player {
	t_point	pos;
	t_vec2d	look;
}	t_player;

typedef enum e_held_keys {
	Key_Left,
	Key_Right,
	Key_Up,
	Key_Up_alt,
	Key_Down,
	Key_Down_alt,
	Key_Rot_Left,
	Key_Rot_Left_alt,
	Key_Rot_Right,
	Key_Rot_Right_alt,
}	t_held_keys;

typedef struct s_env
{
	void			*win;
	void			*mlx;
	t_img			*frame;
	t_img			frame1;
	t_img			frame2;
	t_player		player;
	t_vector		lines;
	t_graphics		graphics;
	t_held_keys		held_keys;
	double			angles[WIDTH];
}	t_env;

int		init_env(t_env *env);
void	switch_frame(t_env *env);
void	destroy_env(t_env *env);
#endif