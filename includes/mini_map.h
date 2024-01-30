/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:43:29 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/30 13:00:56 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MAP_H
# define MINI_MAP_H

# include "env.h"

/* *** mini_map.h *** */

void	render_mini_map(t_img *mini, const t_map *map,
			const t_player *player);

#endif /* *** MINI_MAP_H *** */
