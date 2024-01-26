/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:06:56 by OrioPrisc         #+#    #+#             */
/*   Updated: 2024/01/26 16:29:21 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

typedef struct s_vector	t_vector;

char		*trim_line(char *s);
void		free_tab(char **tab);
int			tab_size(char **tab);
void		free_str(void *data);
int			clean_close(t_vector *cub, int fd);
char		**vector_to_2dtab(const t_vector *cub, size_t max_x);

#endif
