/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_to_2dtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:23:38 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/26 16:29:53 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include "utils.h"

char	**vector_to_2dtab(const t_vector *cub, size_t max_x)
{
	size_t	i;
	size_t	j;
	char	**map;

	i = -1;
	map = ft_calloc(cub->size + 1, sizeof(char *));
	if (!map)
		return (NULL);
	while (++i < cub->size)
	{
		map[i] = ft_calloc(max_x + 1, sizeof(char));
		if (!map[i])
			return (free_tab(map), NULL);
		j = -1;
		while (++j < ft_strlen(((char **)cub->data)[i]))
		{
			map[i][j] = ((char **)cub->data)[i][j];
		}
		while (j < max_x)
			map[i][j++] = ' ';
		map[i][j] = 0;
	}
	map[i] = 0;
	return (map);
}
