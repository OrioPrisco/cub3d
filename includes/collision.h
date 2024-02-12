/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:04:37 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/12 13:17:48 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H
# include "math_utils.h"

# define STEP 0.15
# include <stddef.h>

typedef struct s_player	t_player;
typedef struct s_vector	t_vector;

t_vec2d	move_player(t_player *player, const t_line *lines, size_t solid_lines,
			t_vec2d vec);

#endif
