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

static int	get_nb_lines(char *line, t_data *data, int *index)
{
	int	i;

	i = 0;
	while (line[i] >= '0' && (line[i] <= '9'))
	{
		data->nb_lines = (data->nb_lines * 10) + (line[i] - 48);
		i++;
	}
	if (i == 0)
		return (1);
	*index = i;
	return (0);
}

static int	get_map_data(char *line, t_data *data, int *index)
{
	int	i;
	int	j;

	i = *index;
	j = 0;
	while (line[i] != '\0')
	{
		if (j == 0 && isalnum_bsq(line[i]))
			data->space = line[i];
		else if (j == 1 && isalnum_bsq(line[i]))
			data->obstacle = line[i];
		else if (j == 2 && isalnum_bsq(line[i]))
			data->square = line[i];
		j++;
		i++;
	}
	if (j != 4)
		return (-1);
	return (0);
}

static int	get_data(char *line, t_data *data)
{
	int	index;

	index = 0;
	if (get_nb_lines(line, data, &index))
		return (1);
	if (get_map_data(line, data, &index))
		return (1);
	if (data->space != '\0' && data->obstacle != '\0' && data->square != '\0')
		return (0);
	return (1);
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
