/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:33:42 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/17 15:21:18 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	print_error(int ret_value, const char *message,
	const char *value, int option)
{
	printf("Error\n");
	if (option == 1)
		ft_dprintf(2, "%s\n", message);
	if (option == 2)
		ft_dprintf(2, "%s %s\n", message, value);
	if (option == 3)
		ft_dprintf(2, "%s %c\n", message, *value);
	return (ret_value);
}

void	exit_wrong_input(int ac, const char *av_one)
{
	if (ac != 2)
		exit(print_error(1, ARG_NB, "", 1));
	if (is_directory(av_one))
		exit(print_error(1, CUB_IS_DIR, "", 1));
	if (!is_extension(av_one, ".cub"))
		exit(print_error(1, IS_NOT_CUB, "", 1));
}
