/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:03:08 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/08 13:04:42 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

t_vec2d	vec2d_to(t_point from, t_point to)
{
	return ((t_vec2d){to.x - from.x, to.y - from.y});
}