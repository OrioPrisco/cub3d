/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:55:08 by mpeulet           #+#    #+#             */
/*   Updated: 2023/12/05 18:21:07 by mpeulet          ###   ########.fr       */
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
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}		t_textures;

typedef struct s_map
{
	int		height;
}		t_map;

/* *** colors.c *** */

void	free_tab(char **tab);
int		tab_size(char **tab);
int		convert_rgb(char *r, char *g, char *b);
int		rgb_to_int(char *rgb);

/* *** convert_cub_to_vector.c *** */

void	free_str(void *data);
int		cub_to_vector(t_vector	*cub, int fd);

/* *** parse_utils.c *** */

int		is_file_readable(char *file);
bool	is_cub(char *file);
bool	is_xpm(char *file);
bool	is_directory(char *file);

#endif
