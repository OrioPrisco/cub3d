/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:50:21 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/01/10 23:32:13 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"
#include <math.h>

t_vec2d	vec2d_rotate(t_vec2d vec, double angle)
{
	double	cos_theta;
	double	sin_theta;
	t_vec2d	out;

	cos_theta = cos(angle);
	sin_theta = sin(angle);
	out.x = vec.x * cos_theta - vec.y * sin_theta;
	out.y = vec.x * sin_theta + vec.y * cos_theta;
	return (out);
}

t_vec2d	vec2d_mul(t_vec2d vec, double mult)
{
	vec.x *= mult;
	vec.y *= mult;
	return (vec);
}

double	vec2d_len2(t_vec2d vec)
{
	return (vec.x * vec.x + vec.y * vec.y);
}

t_vec2d	vec2d_to_unit(t_vec2d vec)
{
	double	len;

	len = sqrt(vec2d_len2(vec));
	vec.x /= len;
	vec.y /= len;
	return (vec);
}

t_point	point_add_vec2d(t_point point, t_vec2d vec2d)
{
	point.x += vec2d.x;
	point.y += vec2d.y;
	return (point);
}
