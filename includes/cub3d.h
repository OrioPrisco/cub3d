/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:17:19 by mpeulet           #+#    #+#             */
/*   Updated: 2023/12/03 14:32:12 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "messages.h"

typedef struct t_map
{
    int     cub_lines;
    char    *textures[4];
    int     f_color;
    int     c_color;
    char    **map;
}       s_map;

#endif /* *** CUB3D_H *** */