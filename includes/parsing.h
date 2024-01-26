/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:55:08 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/26 16:02:09 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_vector	t_vector;

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
	size_t	max_x;
	size_t	max_y;
}	t_player_info;

/* *** convert_cub_to_vector.c *** */

void		init_cub_vector(t_vector *cub, const char *av_one);

/* *** debug_print_cub.c *** */

void		print_vector_fd(const t_vector *cub, int fd);
void		int_to_rgb(int value, int *r, int *g, int *b);
void		print_t_textures(const t_textures *textures, int fd);
void		print_player(const t_vector *cub,
				const t_player_info *player, int fd);
void		print_map_copy(const char **map, int fd);

/* *** extract_colors.c *** */

int			extract_colors(t_vector *cub, t_textures *textures);

/* *** error_management.c *** */

int			print_error(int ret_value, const char *message,
				const char *value, int option);
void		exit_wrong_input(int ac, const char *av_one);

/* *** extract_textures.c *** */

int			extract_textures(t_vector *cub, t_textures *textures, size_t size);
void		free_textures(t_textures *textures);

/* *** is_map_playable.c *** */

char		**copy_vector(const t_vector *cub, size_t max_x);
int			flood_fill(char **map, const t_player_info *player);

/* *** parse_map.c *** */

int			find_player(const t_vector *cub, t_player_info *player);

/* *** parse_utils.c *** */

const char	*line_content(const char *line, const char *identifier);
bool		is_file_readable(const char *file);
bool		is_extension(const char *file, const char *ext);
bool		is_directory(const char *file);

#endif
