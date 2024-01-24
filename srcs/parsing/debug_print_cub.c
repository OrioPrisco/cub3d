/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_cub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0202/01/16 13:39:05 by  mpeulet          #+#    #+#             */
/*   Updated: 2024/01/24 12:42:08 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "ft_printf.h"
#include "vector.h"
#include "libft.h"

void	print_vector_fd(const t_vector *cub, int fd)
{
	size_t	i;

	i = 0;
	ft_dprintf(fd, "MAP-----------------------------------------\n");
	while (i < cub->size)
		ft_dprintf(fd, "%s\n", ((char **)cub->data)[i++]);
	ft_dprintf(fd, "--------------------------------------------\n");
	ft_dprintf(fd, "Number of lines :[%d]\n", cub->size);
	ft_dprintf(fd, "MAP_END-------------------------------------\n\n");
}

void	int_to_rgb(int value, int *r, int *g, int *b)
{
	*r = (value >> 16) & 0xFF;
	*g = (value >> 8) & 0xFF;
	*b = value & 0xFF;
}

void	print_t_textures(const t_textures *textures, int fd)
{
	int	r;
	int	g;
	int	b;

	ft_dprintf(fd, "NO : [%s] (%d)\n", textures->no_path,
		ft_strlen(textures->no_path));
	ft_dprintf(fd, "SO : [%s] (%d)\n", textures->so_path,
		ft_strlen(textures->so_path));
	ft_dprintf(fd, "WE : [%s] (%d)\n", textures->we_path,
		ft_strlen(textures->we_path));
	ft_dprintf(fd, "EA : [%s] (%d)\n", textures->ea_path,
		ft_strlen(textures->ea_path));
	ft_dprintf(fd, "--------------------------------------------\n");
	int_to_rgb(textures->colors[0], &r, &g, &b);
	ft_dprintf(fd, "Floor : [%d]// RGB: (%d, %d, %d)\n",
		textures->colors[0], r, g, b);
	int_to_rgb(textures->colors[1], &r, &g, &b);
	ft_dprintf(fd, "Ceiling : [%d]// RGB: (%d, %d, %d)\n",
		textures->colors[1], r, g, b);
}

void	print_player(const t_vector *cub, const t_player_info *player, int fd)
{
	ft_dprintf(fd, "Map size : [%d] x [%d]\n", cub->size, player->max_x);
	ft_dprintf(fd, "--------------------------------------------\n");
	ft_dprintf(fd, "Player facing : [%c]\n", player->facing);
	ft_dprintf(fd, "--------------------------------------------\n");
	ft_dprintf(fd, "Player y : [%d]\n", player->y);
	ft_dprintf(fd, "Player x : [%d]\n", player->x);
}

void	print_map_copy(const char **map, int fd)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_dprintf(fd, "[%s] | len : [%d]\n", map[i], ft_strlen(map[i]));
		i++;
	}
}
