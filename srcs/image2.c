/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:21:02 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/12 18:13:17 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

int	get_pixel(const t_img *img, int x, int y)
{
	unsigned char	*dest;

	dest = img->data + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(int *)dest);
}
