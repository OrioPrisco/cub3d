/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubParsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:45:59 by mpeulet           #+#    #+#             */
/*   Updated: 2023/12/01 14:46:59 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	is_file_readable(char *file)
{
	if (open(file, O_RDONLY))
		return (perror("Opening file "), 0);
}

int	open_cub(char *av)
{
	if (open(av, O_RDONLY))
		return (perror("Opening file "), 1);	
}
