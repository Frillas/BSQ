/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:25:31 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/22 18:30:29 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	check_nb_lines(char **map, t_data *data, char *line, int *index)
{
	int	i;

	i = *index;
	if (i >= data->nb_lines)
	{
		free_mem(line, map, i);
		return (1);
	}
	return (0);
}

static int	is_valid_line(char **map, t_data *data, char *line, int *index)
{
	size_t	size;
	int		j;

	j = 0;
	size = strlen_bsq(line);
	if (*index == 0)
		data->line_len = size;
	if (size != data->line_len || line[size - 1] != '\n')
	{
		free_mem(line, map, *index);
		return (1);
	}
	while (line[j] != '\n')
	{
		if (line[j] != data->space && line[j] != data->obstacle)
		{
			free_mem(line, map, *index);
			return (1);
		}
		j++;
	}
	return (0);
}

int	read_all_lines(FILE *file, char **map, t_data *data)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (1)
	{
		line = getline_bsq(file);
		if (line == NULL)
			break ;
		if (check_nb_lines(map, data, line, &i))
			return (1);
		if (is_valid_line(map, data, line, &i))
			return (1);
		map[i] = line;
		line = NULL;
		i++;
	}
	if (i < data->nb_lines)
	{
		free_map(map, i);
		return (1);
	}
	return (0);
}
