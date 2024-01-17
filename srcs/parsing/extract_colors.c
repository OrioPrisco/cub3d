/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:36:13 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/17 15:03:23 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	convert_rgb(const char *r, const char *g, const char *b)
{
	long	int_r;
	long	int_g;
	long	int_b;
	char	*endptr[3];

	int_r = ft_strtol(r, &endptr[0], 10);
	int_g = ft_strtol(g, &endptr[1], 10);
	int_b = ft_strtol(b, &endptr[2], 10);
	if (ft_strtol_check_int(r, endptr[0], int_r)
		|| *ft_next_non_space(endptr[0])
		|| ft_strtol_check_int(g, endptr[1], int_g)
		|| *ft_next_non_space(endptr[1])
		|| ft_strtol_check_int(b, endptr[2], int_b)
		|| *ft_next_non_space(endptr[2]))
		return (-1);
	if (int_r < 0 || int_g < 0 || int_b < 0 || int_r > 255
		|| int_g > 255 || int_b > 255)
		return (-1);
	return ((int_r << 16) | (int_g << 8) | int_b);
}

char	**rgb_to_int(const char *rgb)
{
	char	**r_g_b;

	r_g_b = ft_split(rgb, ',');
	if (!r_g_b)
		return (NULL);
	if (tab_size(r_g_b) != 3)
		return (free_tab(r_g_b), NULL);
	return (r_g_b);
}

int	vector_to_int(const char *color_line, t_textures *textures, int color)
{
	char			**rgb;
	const char		*res;

	res = ft_next_non_space(color_line);
	res++;
	res = ft_next_non_space(res);
	rgb = rgb_to_int(res);
	if (!rgb)
		return (0);
	textures->colors[color] = convert_rgb(rgb[0], rgb[1], rgb[2]);
	if (textures->colors[color] == -1)
		return (free_tab(rgb), 0);
	free_tab(rgb);
	return (1);
}

int	extract_colors_utils(t_vector *cub, int i, t_textures *textures, int color)
{
	char	*tmp;

	tmp = 0;
	if (!vector_to_int(((char **)cub->data)[i], textures, color))
		return (0);
	vector_pop(cub, i, &tmp);
	free(tmp);
	tmp = 0;
	return (1);
}

int	extract_colors(t_vector *cub, t_textures *textures, size_t size, size_t i)
{
	while (++i < 6)
	{
		if (line_identifier(((char **)cub->data)[i], "F") != NULL)
		{
			if (!extract_colors_utils(cub, i, textures, 0))
				return (print_error(0, F_FORMAT, ((char **)cub->data)[i], 2));
			break ;
		}
	}
	if (i == 6)
		return (print_error(0, F_MISSING, "", 1));
	i = -1;
	while (++i < 5)
	{
		if (line_identifier(((char **)cub->data)[i], "C") != 0)
		{
			if (!extract_colors_utils(cub, i, textures, 1))
				return (print_error(0, C_FORMAT, ((char **)cub->data)[i], 2));
			break ;
		}
	}
	if (cub->size != size - 2)
		return (print_error(0, C_MISSING, "", 1));
	return (1);
}
