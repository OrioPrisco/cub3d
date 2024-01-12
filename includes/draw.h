/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:18:16 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/01/12 16:56:43 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stddef.h>

typedef struct s_img	t_img;
typedef struct s_line	t_line;
typedef struct s_vector	t_vector;
typedef struct s_player	t_player;
typedef struct s_env	t_env;

typedef struct s_column {
	t_img	*image;
	size_t	col;
}	t_column;

void	draw_screen(t_img *image, const t_player *player,
			const t_env *env);
#endif
