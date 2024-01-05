/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_cub_to_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:02:39 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/05 17:16:51 by mpeulet          ###   ########.fr       */
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

/*int	cub_to_vector(t_vector	*cub, int fd)
{
	char	*line;

	if (fd == -42)
		return (0);
	vector_init(cub, sizeof(char **));
	line = get_next_line(fd);
	while (!get_next_line(fd))
	{
		while (!ft_strcmp(line, "\n"))
		{
			free(line);
			line = get_next_line(fd);
		}
		if (vector_append(cub, &line))
			return (clean_close(cub, fd));
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}*/

/*int	clean_vector(t_vector *cub)
{
	size_t	i;

	i = 0;
	while (i < cub->size)
	{
		if (!cub->data)
			vector_copy_n()
	}
}*/

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

int	vector_to_int(char *color_line, t_textures *textures)
{
	char	**rgb;
	char	*res;

	color_line++;
	res = ft_strdup(ft_next_non_match(color_line, ft_isspace));
	rgb = rgb_to_int(res);
	if (!rgb)
		return (-1);
	textures->f_color = convert_rgb(rgb[0], rgb[1], rgb[2]);
	printf("%d\n", textures->f_color);
	free_tab(rgb);
	free(res);
	return (0);
}

int	extract_colors(t_vector *cub, t_textures *textures)
{
	size_t	i;
	size_t	tmp_size;

	i = -1;
	tmp_size = cub->size;
	while (++i < 6)
	{
		if (!ft_strncmp(((char **)cub->data)[i], "F ", 2))
		{
			vector_to_int(((char **)cub->data)[i], textures);
			// vector_pop(cub, i, &textures->f_color);
			break ;
		}
	}
	i = -1;
	while (++i < 5)
	{
		if (!ft_strncmp(((char **)cub->data)[i], "C ", 2))
		{
			vector_pop(cub, i, &textures->c_color);
			break ;
		}
	}
	if (cub->size != tmp_size - 2)
		return (printf("No C or F found\n"), 0);
	return (1);
}
