/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:00:22 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/15 17:25:31 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

const char	*line_identifier(const char *line, const char *identifier)
{
	size_t			len;
	const char		*tmp;

	len = ft_strlen(identifier);
	tmp = ft_next_non_space(line);
	if (ft_strlen(tmp) <= len)
		return (0);
	if (ft_strncmp(tmp, identifier, len))
		return (0);
	return (ft_next_non_space(tmp + len));
}

bool	is_file_readable2(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
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

bool	is_extension(const char *file, const char *ext)
{
	int	len;
	int	len_ext;

	if (!file || !ext)
		return (false);
	len_ext = ft_strlen(ext);
	len = ft_strlen(file);
	if (len < 5)
		return (false);
	file += len;
	file -= len_ext;
	return (!ft_strcmp(file, ext));
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
