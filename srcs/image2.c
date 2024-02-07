/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:21:02 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/07 17:47:29 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "mlx.h"

int	get_pixel(const t_img *img, int x, int y)
{
	unsigned char	*dest;

	dest = img->data + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(int *)dest);
}

void	destroy_img(void *mlx, t_img *img)
{
	if (img && img->img)
		mlx_destroy_image(mlx, img->img);
}
