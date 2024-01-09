/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:33:21 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/09 19:10:28 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define WIDTH 800
# define HEIGHT 1200
# include "image.h"
# include <stdbool.h>

typedef struct s_env
{
	void			*win;
	void			*mlx;
	t_img			*frame;
	t_img			frame1;
	t_img			frame2;
}	t_env;

int		init_env(t_env *env);
void	switch_frame(t_env *env);
void	destroy_env(t_env *env);
#endif
