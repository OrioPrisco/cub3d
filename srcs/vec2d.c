/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:50:21 by OrioPrisco        #+#    #+#             */
/*   Updated: 2024/01/10 22:46:28 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"
#include <math.h>

t_vec2d	vec2d_rotate(const t_vec2d *vec, double angle)
{
	double	cos_theta;
	double	sin_theta;
	t_vec2d	out;

	cos_theta = cos(angle);
	sin_theta = sin(angle);
	out.x = vec->x * cos_theta - vec->y * sin_theta;
	out.y = vec->x * sin_theta + vec->y * cos_theta;
	return (out);
}

t_vec2d	vec2d_mul(const t_vec2d *vec, double mult)
{
	t_vec2d	out;

	out = *vec;
	out.x *= mult;
	out.y *= mult;
	return (out);
}

double	vec2d_len2(const t_vec2d *vec)
{
	return (vec->x * vec->x + vec->y * vec->y);
}

t_vec2d	vec2d_to_unit(const t_vec2d *vec)
{
	t_vec2d	out;
	double	len;

	len = sqrt(vec2d_len2(vec));
	out = *vec;
	out.x /= len;
	out.y /= len;
	return (out);
}

t_point	point_add_vec2d(const t_point *point, const t_vec2d *vec2d)
{
	t_point	out;

	out = *point;
	out.x += vec2d->x;
	out.y += vec2d->y;
	return (out);
}
