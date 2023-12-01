/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/12/01 14:52:10 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	is_file_readable(char *file)
{
	if (open(file, O_RDONLY) == -1)
		return (perror("Opening file "), 0);
    return (1);
}

int	main(int ac, char **av)
{
    if (ac != 2)
        return (printf("Wrong arg\n"), 1);
    if (!is_file_readable(av[1]))
        return (1);
    return (0);
}
