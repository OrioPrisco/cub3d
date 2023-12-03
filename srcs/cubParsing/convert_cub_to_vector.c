/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_cub_to_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:02:39 by mpeulet           #+#    #+#             */
/*   Updated: 2023/12/03 18:02:05 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_printf.h"
#include <stdlib.h>
#include "getnextline.h"

t_vector	*cub_to_vector(char *file)
{
	int			fd;
	char		*line;
	t_vector	*cub;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Pb opening cub\n"), NULL);
	cub = vector_init(cub, sizeof(char **));
	if (vector_allocate(cub, 1))
		return (ft_dprintf(2, "Pb with vector allocation\n"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (vector_append(cub, line))
		{
			ft_dprintf(2, "Pb with vector append gnl\n");
			return (free(vector_free(cub, &free)), NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (cub);
}
