/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:50:21 by OrioPrisco        #+#    #+#             */
/*   Updated: 2023/12/07 19:28:31 by OrioPrisco       ###   ########.fr       */
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
