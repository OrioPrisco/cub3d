/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:55:08 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/12 17:38:14 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include "libft.h"
# include "vector.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_textures
{
	const char	*no_path;
	const char	*so_path;
	const char	*we_path;
	const char	*ea_path;
	int			colors[2];
}		t_textures;

typedef struct s_map
{
	int		height;
}		t_map;

/* *** convert_cub_to_vector.c *** */

int		cub_to_vector(t_vector	*cub, int fd);
int		clear_empty_lines(t_vector *cub);

/* *** extract_colors.c *** */

int		convert_rgb(const char *r, const char *g, const char *b);
char	**rgb_to_int(const char *rgb);
int		vector_to_int(const char *color_line, t_textures *textures, int color);
int		extract_colors_utils(t_vector *cub, int i, t_textures *textures,
			int color);
int		extract_colors(t_vector *cub, t_textures *textures,
			size_t size, size_t i);

/* *** extract_textures.c *** */

int		extract_textures(t_vector *cub, t_textures *textures);

/* *** parse_utils.c *** */

const char	*line_identifier(const char *line, const char *identifier);
int		is_file_readable(const char *file);
bool	is_file_readable2(const char *file);
bool	is_extension(const char *file, const char ext[5]);
bool	is_directory(const char *file);

/* *** small_utils.c *** */

void	free_tab(char **tab);
int		tab_size(char **tab);
void	free_str(void *data);
int		clean_close(t_vector *cub, int fd);

#endif
