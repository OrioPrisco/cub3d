/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/05 14:14:00 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	main(int ac, char **av)
{
    size_t       i;
    t_vector    test;
    t_textures  text_test;

    ft_memset(&text_test, 0, sizeof(t_textures));
    i = 0;
    if (ac != 2)
        return (printf("Wrong arg\n"), 1);
    if (is_directory(av[1]))
        return (printf("is dir\n"), 1);
    if (!is_cub(av[1]))
       return (printf("is not cub\n"), 1);
	if (!cub_to_vector(&test, is_file_readable(av[1])))
		return (printf(INVALID_CUB), 1);
	/*while (i < test.size)
		printf("%s", ((char **)test.data)[i++]);
	printf("\n%zu\n", test.size);*/
    clear_empty_lines(&test);
    if (test.size < 9)
        return (vector_free(&test, &free_str), 0);
    i = 0;
    while (i < test.size)
		printf("%s", ((char **)test.data)[i++]);
    printf("--------------------------------------------\n");
    printf("[%zu]\n", test.size);
    printf("--------------------------------------------\n");
    extract_colors(&test, &text_test);
    i = 0;
    while (i < test.size)
		printf("%s", ((char **)test.data)[i++]);
    printf("--------------------------------------------\n");
	printf("[%zu]\n", test.size);
    printf("--------------------------------------------\n");
	vector_free(&test, &free_str);
    return (0);
}
