/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:43:29 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/29 16:24:59 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MAP_H
# define MINI_MAP_H

# include "env.h"

/* *** mini_map.h *** */

void	render_mini_map(const t_player_info *p_info, t_img *mini, int color,
			char **map, const t_player *player);

#endif /* *** MINI_MAP_H *** */
