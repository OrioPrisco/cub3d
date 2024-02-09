/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:21:02 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/09 14:54:12 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "vector.h"
#include "mlx.h"
#include "ft_printf.h"

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

bool	load_texture(t_vector *vec, const char *path, void *mlx)
{
	t_img	img;

	if (load_xpm(mlx, path, &img))
		return (ft_dprintf(2, "%s : Failed to load\n", path), 1);
	if (vector_append(vec, &img))
		return (destroy_img(mlx, &img), 1);
	return (0);
}
