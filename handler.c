/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:23:36 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/22 18:56:19 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	init_struct(t_data *data)
{
	data->nb_lines = 0;
	data->space = '\0';
	data->obstacle = '\0';
	data->square = '\0';
	data->line_len = 0;
	data->max = 0;
	data->x = 0;
	data->y = 0;
}

int	handler(FILE *file)
{
	char	*line;
	char	**map;
	t_data	data;

	line = read_first_line(file);
	if (line == NULL)
		return (1);
	init_struct(&data);
	if (get_data(line, &data))
	{
		free(line);
		return (1);
	}
	free(line);
	map = read_map(file, &data);
	if (map == NULL)
		return (1);
	find_square(map, &data);
	print_map(map, &data);
	free_map(map, data.nb_lines);
	return (0);
}
