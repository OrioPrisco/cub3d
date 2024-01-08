/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_cub_to_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:02:39 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/08 17:14:15 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_str(void *data)
{
	char	**str;

	str = data;
	if (*str)
		free(*str);
}

int	clean_close(t_vector *cub, int fd)
{
	vector_free(cub, &free_str);
	close(fd);
	return (0);
}

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

int	vector_to_int(char *color_line, t_textures *textures, int color)
{
	char		**rgb;
	char		*res;

	color_line++;
	res = ft_next_non_match(color_line, ft_isspace);
	rgb = rgb_to_int(res);
	if (!rgb)
		return (0);
	textures->colors[color] = convert_rgb(rgb[0], rgb[1], rgb[2]);
	if (textures->colors[color] == -1)
		return (0);
	free_tab(rgb);
	return (1);
}

int	check_input(char *s, char *identifier)
{
	char	*tmp;

	tmp = ft_next_non_space(s);
	if (ft_strncmp(tmp, identifier, ft_strlen(identifier)))
		return (0);
	return (1);
}

int	extract_colors(t_vector *cub, t_textures *textures)
{
	size_t	i;
	size_t	tmp_size;
	char	*tmp;

	i = -1;
	tmp_size = cub->size;
	while (++i < 6)
	{
		if (check_input(((char **)cub->data)[i], "F"))
		{
			vector_to_int(((char **)cub->data)[i], textures, 0);
			vector_pop(cub, i, &tmp);
			free(tmp);
			tmp = 0;
			break ;
		}
	}
	printf("[[%zu]]\n", i);
	if (i == 6)
		return (printf("F not found\n"), 0);
	i = -1;
	while (++i < 5)
	{
		if (check_input(((char **)cub->data)[i], "C"))
		{
			vector_to_int(((char **)cub->data)[i], textures, 1);
			vector_pop(cub, i, &tmp);
			free(tmp);
			tmp = 0;
			break ;
		}
	}
	if (cub->size != tmp_size - 2)
		return (printf("C not found\n"), 0);
	return (1);
}

/*int	extract_textures(t_vector *cub, t_textures *textures)
{
	size_t	i;
	char	*tmp_textures[4];

	i = -1;
	while (++i < 4)
		vector_pop(cub, i, tmp_textures[i]);
	i = -1;
	while (tmp_textures[++i])
	{
		
	}
}*/
