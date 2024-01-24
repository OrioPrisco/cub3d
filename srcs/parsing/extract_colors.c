/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:36:13 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/24 17:46:26 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "vector.h"
#include "messages.h"
#include "utils.h"
#include <stdlib.h>

static const char	*next(const char *str)
{
	if (!*str)
		return (str);
	str = ft_next_non_space(str);
	if (*str != ',')
		return (str);
	return (str + 1);
}

static int	convert_rgb(const char *line)
{
	long		int_r;
	long		int_g;
	long		int_b;
	char		*endptr[3];
	const char	*start[3];

	start[0] = line;
	int_r = ft_strtol(start[0], &endptr[0], 10);
	start[1] = next(endptr[0]);
	int_g = ft_strtol(start[1], &endptr[1], 10);
	start[2] = next(endptr[1]);
	int_b = ft_strtol(start[2], &endptr[2], 10);
	if (ft_strtol_check_int(start[0], endptr[0], int_r)
		|| *ft_next_non_space(endptr[0]) != ','
		|| ft_strtol_check_int(start[1], endptr[1], int_g)
		|| *ft_next_non_space(endptr[1]) != ','
		|| ft_strtol_check_int(start[2], endptr[2], int_b)
		|| *ft_next_non_space(endptr[2]))
		return (-1);
	if (int_r < 0 || int_g < 0 || int_b < 0 || int_r > 255
		|| int_g > 255 || int_b > 255)
		return (-1);
	return ((int_r << 16) | (int_g << 8) | int_b);
}

//assumes the ith line is a Color line
static int	extract_colors_utils(t_vector *cub, size_t i, int *out)
{
	char	*tmp;
	int		color;

	tmp = 0;
	color = convert_rgb(ft_next_non_space(((char **)cub->data)[i]) + 1);
	if (color == -1)
		return (0);
	*out = color;
	vector_pop(cub, i, &tmp);
	free(tmp);
	return (1);
}

int	extract_colors(t_vector *cub, t_textures *textures)
{
	size_t	i;

	i = -1;
	while (++i < 6)
		if (line_content(((char **)cub->data)[i], "F") != NULL)
			break ;
	if (i == 6)
		return (print_error(0, F_MISSING, "", 1));
	if (!extract_colors_utils(cub, i, textures->colors + 0))
		return (print_error(0, F_FORMAT, ((char **)cub->data)[i], 2));
	i = -1;
	while (++i < 5)
		if (line_content(((char **)cub->data)[i], "C") != 0)
			break ;
	if (i == 5)
		return (print_error(0, C_MISSING, "", 1));
	if (!extract_colors_utils(cub, i, textures->colors + 1))
		return (print_error(0, C_FORMAT, ((char **)cub->data)[i], 2));
	return (1);
}
