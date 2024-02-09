/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:23:59 by mpeulet           #+#    #+#             */
/*   Updated: 2024/02/09 14:56:48 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "vector.h"
#include "messages.h"
#include <stdlib.h>
#include "image.h"
#include "mlx.h"

static int	extract_textures_utils(t_vector *cub, const char *id,
	char **dest, int i)
{
	const char			*tmp;
	char				*final;

	tmp = ft_next_non_space(((char **)cub->data)[i]);
	tmp = line_content(tmp, id);
	if (!tmp)
		return (0);
	final = ft_strdup(tmp);
	if (!final)
		return (print_error(0, TEXT_MALLOC_FAIL, "", 4));
	if (!is_extension(final, ".xpm") || is_directory(final)
		|| !is_file_readable(final))
	{
		free(final);
		return (0);
	}
	*dest = final;
	vector_pop(cub, i, &final);
	free(final);
	return (1);
}

int	extract_textures(t_vector *cub, t_textures *textures, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < 4)
		if (extract_textures_utils(cub, "NO", &textures->no_path, i))
			break ;
	if (cub->size != size -1)
		return (print_error(0, NO_MISSING, "", 1));
	i = -1;
	while (++i < 3)
		if (extract_textures_utils(cub, "SO", &textures->so_path, i))
			break ;
	if (cub->size != size -2)
		return (print_error(0, SO_MISSING, "", 1));
	i = -1;
	while (++i < 2)
		if (extract_textures_utils(cub, "WE", &textures->we_path, i))
			break ;
	if (cub->size != size -3)
		return (print_error(0, WE_MISSING, "", 1));
	if (!extract_textures_utils(cub, "EA", &textures->ea_path, 0)
		|| cub->size != size - 4)
		return (print_error(0, EA_MISSING, "", 1));
	return (1);
}

void	free_textures(t_textures *textures)
{
	if (textures->no_path)
		free(textures->no_path);
	if (textures->so_path)
		free(textures->so_path);
	if (textures->we_path)
		free(textures->we_path);
	if (textures->ea_path)
		free(textures->ea_path);
	textures->no_path = 0;
	textures->so_path = 0;
	textures->we_path = 0;
	textures->ea_path = 0;
}

bool	load_textures(t_vector *texture_out, const t_textures *textures,
			void *mlx)
{
	return (0
		|| load_texture(texture_out, textures->no_path, mlx)
		|| load_texture(texture_out, textures->so_path, mlx)
		|| load_texture(texture_out, textures->we_path, mlx)
		|| load_texture(texture_out, textures->ea_path, mlx)
	);
}
