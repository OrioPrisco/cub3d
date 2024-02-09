/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:34:02 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/02/09 14:54:13 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include <stddef.h>
# include <stdbool.h>

typedef struct s_env	t_env;
typedef struct s_vector	t_vector;

typedef struct s_img
{
	void			*img;
	unsigned char	*data;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	int				height;
	int				width;
}	t_img;

//only there because of norm
typedef struct s_graph_line
{
	size_t	x;
	size_t	y;
	size_t	size;
	int		color;
}	t_graph_line;

void			my_mlx_pixel_put(t_img *img, size_t x, size_t y, int color);
void			cpy_img(t_img *dest, const t_img *src);
void			img_put_graph_line(t_img *img, t_graph_line line);
int				init_img(t_env *env, t_img *img, int width, int height);
int				load_xpm(void *mlx, const char *file, t_img *img);
int				get_pixel(const t_img *img, int x, int y);
void			destroy_img(void *mlx, t_img *img);
bool			load_texture(t_vector *vec, const char *path, void *mlx);
#endif
