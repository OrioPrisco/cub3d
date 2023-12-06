/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:15:55 by mpeulet           #+#    #+#             */
/*   Updated: 2023/12/05 17:54:11 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_file_readable(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Opening file "), -42);
	return (fd);
}

bool	is_cub(char *file)
{
	int		len;
	char	*s;

	len = ft_strlen(file);
	s = ft_strnstr(file, ".cub", len);
	if (s && s == file + len - 4)
		return (true);	
	return (false);
}

bool	is_xpm(char *file)
{
	int		len;
	char	*s;

	len = ft_strlen(file);
	s = ft_strnstr(file, ".xpm", len);
	if (s && s == file + len - 4)
		return (true);	
	return (false);
}

bool	is_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}
