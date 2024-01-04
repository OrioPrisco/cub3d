/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:36:13 by mpeulet           #+#    #+#             */
/*   Updated: 2024/01/04 16:40:40 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;  
	return (i);
}

int	convert_rgb(char *r, char *g, char *b)
{
	int		int_r;
	int		int_g;
	int		int_b;

	int_r = ft_atoi(r);
	int_g = ft_atoi(g);
	int_b = ft_atoi(b);
	if (int_r < 0 || int_g < 0 || int_b < 0)
		return (-1);
	return ((int_r << 16) | (int_g << 8) | int_b);
}

int	rgb_to_int(char *rgb)
{
	int		converted_rgb;
	char	**r_g_b;

	r_g_b = ft_split(rgb, ',');
	if (!r_g_b)
		return (-1);
	if (tab_size != 3)
		return (free_tab(r_g_b), -1);
	if 
	free_tab(r_g_b);
	return (0);
}

bool	is_color_f(char *color)
{
	return (true);
}
