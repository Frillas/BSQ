/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:23:27 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/22 18:28:44 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_map(char **map, int nb_lines)
{
	int	i;

	i = 0;
	while (i < nb_lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_int_map(int **int_map, int nb_lines)
{
	int	i;

	i = 0;
	while (i < nb_lines)
	{
		free(int_map[i]);
		i++;
	}
	free(int_map);
	int_map = NULL;
}

void	free_mem(char *line, char **map, int nb_lines)
{
	free(line);
	free_map(map, nb_lines);
}
