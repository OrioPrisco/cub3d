/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/12/03 18:27:38 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "parsing.h"
#include "ft_printf.h"
#include "vector.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

t_vector	cub_to_vector(char *file)
{
	int			fd;
	char		*line;
	t_vector	cub;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Pb opening cub\n"), 0);
	vector_init(&cub, sizeof(char **));
	if (vector_allocate(&cub, 1))
		return (ft_dprintf(2, "Pb with vector allocation\n"), 0);
	line = get_next_line(fd);
	while (line)
	{
		if (vector_append(&cub, line))
		{
			ft_dprintf(2, "Pb with vector append gnl\n");
			return (free(vector_free(&cub, &free)), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (cub);
}

int	main(int ac, char **av)
{
    size_t       i;
    t_vector    test;

    i = 0;
    if (ac != 2)
        return (printf("Wrong arg\n"), 1);
    if (is_directory(av[1]))
        return (printf("is dir\n"), 1);
    if (!is_cub(av[1]))
       return (printf("is not cub\n"), 1); 
    test = cub_to_vector(av[1]);
    while (i < test.size)
        printf("%s\n", test.data);
    return (0);
}
