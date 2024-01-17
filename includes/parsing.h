/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:55:08 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/17 16:35:56 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# include "libft.h"
# include "vector.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include "messages.h"

typedef struct s_textures
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		colors[2];
}		t_textures;

typedef struct s_player_info
{
	char	facing;
	size_t	y;
	size_t	x;
	size_t	x_line_len;
	size_t	max_x;
	size_t	nb_player;
}	t_player_info;

/* *** convert_cub_to_vector.c *** */

int			cub_to_vector(t_vector	*cub, int fd);
int			clear_empty_lines(t_vector *cub);
void		init_cub_vector(t_vector *cub, const char *av_one);

/* *** debug_print_cub.c *** */

void		print_vector_fd3(const t_vector *cub, int fd);
void		int_to_rgb(int value, int *r, int *g, int *b);
void		print_t_textures(const t_textures *textures, int fd);
void		print_player(const t_vector *cub, const t_player_info *player, int fd);

/* *** extract_colors.c *** */

int			convert_rgb(const char *r, const char *g, const char *b);
char		**rgb_to_int(const char *rgb);
int			vector_to_int(const char *color_line,
				t_textures *textures, int color);
int			extract_colors_utils(t_vector *cub, int i, t_textures *textures,
				int color);
int			extract_colors(t_vector *cub, t_textures *textures,
				size_t size, size_t i);

/* *** error_management.c *** */

int			print_error(int ret_value, const char *message,
				const char *value, int option);
void		exit_wrong_input(int ac, const char *av_one);

/* *** extract_textures.c *** */

int			extract_textures_utils(t_vector *cub, const char *id,
				char **dest, int i);
int			extract_textures(t_vector *cub, t_textures *textures, size_t size);
void		free_textures(t_textures *textures);

/* *** parse_map.c *** */

int			find_player(t_vector *cub, t_player_info *player, size_t i, size_t j);

/* *** parse_utils.c *** */

const char	*line_identifier(const char *line, const char *identifier);
int			is_file_readable_cub(const char *file);
bool		is_file_readable(const char *file);
bool		is_extension(const char *file, const char *ext);
bool		is_directory(const char *file);

/* *** small_utils.c *** */

char		*trim_line(char *s);
void		free_tab(char **tab);
int			tab_size(char **tab);
void		free_str(void *data);
int			clean_close(t_vector *cub, int fd);

#endif
