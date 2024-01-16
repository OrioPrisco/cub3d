/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_cub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:39:58 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/16 14:27:59 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_vector_fd3(const t_vector *cub)
{
	size_t	i;

	i = 0;
	ft_dprintf(3, "MAP-----------------------------------------\n");
	while (i < cub->size)
		ft_dprintf(3, "%s\n", ((char **)cub->data)[i++]);
	ft_dprintf(3, "--------------------------------------------\n");
	ft_dprintf(3, "Number of lines :[%d]\n", cub->size);
	ft_dprintf(3, "MAP_END-------------------------------------\n\n");
}

void	int_to_rgb(int value, int *r, int *g, int *b)
{
	*r = (value >> 16) & 0xFF;
	*g = (value >> 8) & 0xFF;
	*b = value & 0xFF;
}

void	print_t_textures(const t_textures *textures)
{
	int	r;
	int	g;
	int	b;

	ft_dprintf(4, "NO : [%s] (%d)\n", textures->no_path,
		ft_strlen(textures->no_path));
	ft_dprintf(4, "SO : [%s] (%d)\n", textures->so_path,
		ft_strlen(textures->so_path));
	ft_dprintf(4, "WE : [%s] (%d)\n", textures->we_path,
		ft_strlen(textures->we_path));
	ft_dprintf(4, "EA : [%s] (%d)\n", textures->ea_path,
		ft_strlen(textures->ea_path));
	ft_dprintf(4, "--------------------------------------------\n");
	int_to_rgb(textures->colors[0], &r, &g, &b);
	ft_dprintf(4, "Floor : [%d]// RGB: (%d, %d, %d)\n",
		textures->colors[0], r, g, b);
	int_to_rgb(textures->colors[1], &r, &g, &b);
	ft_dprintf(4, "Ceiling : [%d]// RGB: (%d, %d, %d)\n",
		textures->colors[1], r, g, b);
}
