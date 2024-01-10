/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:18:16 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/01/10 20:24:34 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stddef.h>

typedef struct s_img	t_img;
typedef struct s_line	t_line;
typedef struct s_vector	t_vector;

typedef struct s_column {
	t_img	*image;
	size_t	col;
}	t_column;

void	draw_column(t_column *column, const t_line *ray,
			const t_line *look, const t_vector *lines);

#endif
