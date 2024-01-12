/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:23:59 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/12 17:45:01 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "messages.h"

int	extract_textures(t_vector *cub, t_textures *textures)
{
	int				i;
	const char		*tmp;
	char			*free_s;

	i = 0;
	tmp = 0;
	tmp = ft_next_non_space(((char **)cub->data)[i]);
	tmp = line_identifier(tmp, "NO");
	if (!is_extension(tmp, ".xpm") || is_directory(tmp) || !is_file_readable2(tmp))
		return (0);
	textures->no_path = ft_strdup(tmp);
	if (!textures->no_path)
		return (0);
	vector_pop(cub, i, &free_s);
	free(free_s);
	tmp = 0;
	return (1);
}

		// if (!line_identifier(((char **)cub->data)[i], "NO")
		// 	|| !line_identifier(((char **)cub->data)[i], "SO")
		// 	|| !line_identifier(((char **)cub->data)[i], "WE")
		// 	|| !line_identifier(((char **)cub->data)[i], "EA"))
		// 		return (0);
		// if (!is_extension(((char **)cub->data)[i], ".xpm"))
		// 	return (0);