/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:33:21 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/08 18:34:09 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define WIDTH 1900
# define HEIGHT 1000
# include "vector.h"
# include "image.h"
# include <stdbool.h>
# include "math_utils.h"
# include "map.h"

typedef struct s_textures		t_textures;
typedef struct s_player_info	t_player_info;

typedef struct s_door {
	size_t	line_id;
	size_t	timer;
	bool	interacted;
	bool	opened;
}	t_door;

typedef struct s_graphics {
	t_vector	textures;
	t_vector	line_textures_id;
	t_vector	doors;
	t_vector	sprites_id;
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
	Key_Map,
}	t_held_keys;

typedef struct s_env
{
	void			*win;
	void			*mlx;
	t_img			*frame;
	t_img			frame1;
	t_img			frame2;
	t_img			mini_map;
	t_player		player;
	t_vector		lines;
	t_graphics		graphics;
	t_held_keys		held_keys;
	double			angles[WIDTH];
	bool			bonus;
	int				timer;
	t_map			map;
}	t_env;

int		init_env(t_env *env);
void	switch_frame(t_env *env);
void	destroy_env(t_env *env);
bool	load_into_env(t_env *env, const t_vector *cub,
			const t_textures *textures, const t_player_info *player_info);
#endif
