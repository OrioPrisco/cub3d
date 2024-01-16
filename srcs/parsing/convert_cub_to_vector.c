/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_cub_to_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:02:39 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/16 17:30:05 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	cub_to_vector(t_vector *cub, int fd)
{
	char	*line;

	if (fd == -42)
		exit(print_error(errno, strerror(errno), OPEN_CUB, 2));
	vector_init(cub, sizeof(char **));
	line = get_next_line(fd);
	while (line)
	{
		line = trim_line(line);
		if (vector_append(cub, &line))
			return (close(fd), free(line), vector_free(cub, free_str),
				print_error(0, VECTOR_APP_ERR, "", 1));
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
		if (!*(((char **)cub->data)[i]))
		{
			vector_pop(cub, i, &tmp);
			free(tmp);
		}
		else
			i++;
	}
	return (1);
}

void	init_cub_vector(t_vector *cub, const char *av_one)
{
	char	*tmp;

	if (cub_to_vector(cub, is_file_readable_cub(av_one)) != 1)
		exit(1);
	clear_empty_lines(cub);
	if (cub->size < 9)
	{
		tmp = ft_itoa(cub->size);
		if (!tmp)
			print_error(1, "Itoa failed", "", 1);
		else
			print_error(1, INVALID_SIZE, tmp, 2);
		free(tmp);
		vector_free(cub, &free_str);
		exit(1);
	}
}
