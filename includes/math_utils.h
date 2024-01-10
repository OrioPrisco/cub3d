/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:06:07 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/01/10 23:17:15 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include <stdbool.h>

typedef struct s_point {
	double	x;
	double	y;
}	t_point;

typedef t_point	t_vec2d;

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
double	distance2(t_point a, t_point b);
//returns the slope of a line, in the form y=mx+b
//caution: m might be infinite
t_slope	get_slope(t_line line);
// checks that value is between the unordered bound 1 & 2
bool	is_between(double value, double bound1, double bound2);
double	orth_distance(t_line line, t_point point);

//vec2d stuff
t_vec2d	vec2d_rotate(t_vec2d vec, double angle);
t_vec2d	vec2d_mul(t_vec2d vec, double mult);
double	vec2d_len2(t_vec2d vec);
t_vec2d	vec2d_to_unit(t_vec2d vec);
t_point	point_add_vec2d(t_point point, t_vec2d vec2d);
#endif
