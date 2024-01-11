/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:27:52 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/11 17:08:37 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "libft.h"
#include "mlx.h"
#include "env.h"

int	init_img(t_env *env, t_img *img, int width, int height)
{
	img->img = 0;
	img->img = mlx_new_image(env->mlx, width, height);
	if (!img->img)
		return (1);
	img->data = (unsigned char *)mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->height = height;
	img->width = width;
	return (0);
}

int	load_xpm(void *mlx, const char *file, t_img *img)
{
	img->img = mlx_xpm_file_to_image
		(mlx, (char *)file, &img->width, &img->height);
	if (!img->img)
		return (1);
	img->data = (unsigned char *)mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	return (0);
}

void	img_put_graph_line(t_img *img, t_graph_line line)
{
	unsigned char	*dest;

	if (img->bits_per_pixel != sizeof(int) * 8)
	{
		while (line.size--)
			(my_mlx_pixel_put(img, line.x++, line.y, line.color));
		return ;
	}
	dest = img->data + (line.y * img->line_length + line.x * sizeof(int));
	while (line.size--)
	{
		*(int *)dest = line.color;
		dest += sizeof(int);
	}
}

void	my_mlx_pixel_put(t_img *img, size_t x, size_t y, int color)
{
	unsigned char	*dest;

	dest = img->data + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)dest = color;
}

//TODO : optimizations for line of different sizes
void	cpy_img(t_img *dest, const t_img *src)
{
	int	x;
	int	y;

	if (src->bits_per_pixel == dest->bits_per_pixel && src->width == dest->width
		&& src->height == dest->height && src->line_length == dest->line_length
		&& src->endian == dest->endian)
		return ((void)ft_memcpy(dest->data, src->data,
				dest->line_length * dest->height));
	y = 0;
	while (y < dest->height && y < src->height)
	{
		x = 0;
		while (x < dest->width && x < src->width)
		{
			*(int *)(src->data + (y * src->line_length + x
						* (src->bits_per_pixel / 8))) = *(int *)(dest->data
					+ (y * dest->line_length + x * (dest->bits_per_pixel / 8)));
			x++;
		}
		y++;
	}
}
