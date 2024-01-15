/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:23:59 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/15 17:10:30 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	extract_textures_utils(t_vector *cub, const char *id,
	char **dest, int i)
{
	const char			*tmp;
	char				*final;

	tmp = 0;
	tmp = ft_next_non_space(((char **)cub->data)[i]);
	tmp = line_identifier(tmp, id);
	if (!tmp)
		return (0);
	final = ft_strdup(tmp);
	if (!final)
		return (0);
	if (!is_extension(final, ".xpm") || is_directory(final)
		|| !is_file_readable2(final))
	{
		free(final);
		return (0);
	}
	*dest = final;
	vector_pop(cub, i, &final);
	free(final);
	final = 0;
	tmp = 0;
	return (1);
}

int	extract_textures(t_vector *cub, t_textures *textures, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < 4)
	{
		if (extract_textures_utils(cub, "NO", &textures->no_path, i))
			break ;
	}
	i = -1;
	while (++i < 3)
	{
		if (extract_textures_utils(cub, "SO", &textures->so_path, i))
			break ;
	}
	i = -1;
	while (++i < 2)
	{
		if (extract_textures_utils(cub, "WE", &textures->we_path, i))
			break ;
	}
	if (!extract_textures_utils(cub, "EA", &textures->ea_path, 0)
		|| cub->size != size - 4)
		return (0);
	return (1);
}
