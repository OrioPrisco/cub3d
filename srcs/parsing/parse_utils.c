/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:00:22 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/11 14:13:32 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	line_identifier(const char *line, const char *identifier)
{
	const char	*tmp;

	tmp = ft_next_non_space(line);
	if (ft_strncmp(tmp, identifier, ft_strlen(identifier)))
		return (0);
	return (1);
}

//TODO : don't forget to close the fd
int	is_file_readable(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Opening file "), -42);
	return (fd);
}

//should foo.cub.cub work ?
bool	is_cub(const char *file)
{
	int			len;
	const char	*s;

	len = ft_strlen(file);
	s = ft_strnstr(file, ".cub", len);
	if (s && s == file + len - 4)
		return (true);
	return (false);
}

//should foo.xpm.xpm work ?
bool	is_xpm(const char *file)
{
	int			len;
	const char	*s;

	len = ft_strlen(file);
	s = ft_strnstr(file, ".xpm", len);
	if (s && s == file + len - 4)
		return (true);
	return (false);
}

bool	is_directory(const char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}
