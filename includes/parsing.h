/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:55:08 by mpeulet           #+#    #+#             */
/*   Updated: 2023/12/03 14:18:58 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"

/* *** parse_utils.c *** */

bool	is_file_readable(char *file);
bool	is_cub(char *file);
bool	is_xpm(char *file);
bool	is_directory(char *file);

#endif
