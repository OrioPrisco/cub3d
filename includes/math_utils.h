/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:06:07 by OrioPrisco        #+#    #+#             */
/*   Updated: 2023/11/30 20:01:04 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

typedef struct s_point {
	double	x;
	double	y;
}	t_point;

typedef struct s_line {
	t_point	start;
	t_point	end;
}	t_line;

// y = mx + b
typedef struct s_slope {
	double	m;
	double	b;
}	t_slope;

//returns the squared of the distance between two points
double	distance2(const t_point *a, const t_point *b);
//returns the slope of a line, in the form y=mx+b
//caution: m might be infinite
t_slope	get_slope(const t_line *line);
#endif
