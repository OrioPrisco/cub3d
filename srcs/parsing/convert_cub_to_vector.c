/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_cub_to_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:02:39 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/09 18:03:37 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	cub_to_vector(t_vector	*cub, int fd)
{
	char	*line;

	vector_init(cub, sizeof(char **));
	line = get_next_line(fd);
	while (line)
	{
		if (vector_append(cub, &line))
			return (0);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	clear_empty_lines(t_vector *cub)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = 0;
	while (i < cub->size)
	{
		if (!ft_strcmp(((char **)cub->data)[i], "\n"))
		{
			vector_pop(cub, i, &tmp);
			free(tmp);
		}
		else
			i++;
	}
	return (1);
}
