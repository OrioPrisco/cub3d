/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:04:37 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/09 12:53:50 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H
# include "math_utils.h"

# define STEP 0.15

typedef struct s_player	t_player;
typedef struct s_vector	t_vector;

t_vec2d	move_player(t_player *player, const t_vector *lines, bool bonus,
			t_vec2d vec);

#endif
