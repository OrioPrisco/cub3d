/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:33:21 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/11 16:36:02 by OrioPrisc        ###   ########.fr       */
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

typedef struct s_player {
	t_point	pos;
	t_vec2d	look;
}	t_player;

typedef struct s_env
{
	void			*win;
	void			*mlx;
	t_img			*frame;
	t_img			frame1;
	t_img			frame2;
	t_player		player;
	t_vector		lines;
	double			angles[WIDTH];
}	t_env;

int		init_env(t_env *env);
void	switch_frame(t_env *env);
void	destroy_env(t_env *env);
#endif
