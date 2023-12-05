/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/12/05 18:17:33 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

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
	if (!cub_to_vector(&test, is_file_readable(av[1])))
		return (printf(INVALID_CUB), 1);
	while (i < test.size)
		printf("%s", ((char **)test.data)[i++]);
	printf("\n%zu\n", test.size);
	vector_free(&test, &free_str);
    return (0);
}
