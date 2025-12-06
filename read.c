/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:23:51 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/22 18:29:43 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	create_map(FILE *file, t_data *data)
{
	char	*line;

	data->map = (char **)malloc(data->nb_lines * sizeof(char *));
	if (data->map == NULL)
		return (1);
	line = getline_bsq(file);
	if (line == NULL)
	{
		free_map(data->map, 0);
		return (1);
	}
	if (check_line_size(line, data))
	{
		free_map(data->map, 0);
		free(line);
		return (1);
	}
	data->map[0] = line;
	return (0);
}

static int	create_int_lines(int **current, int **prev, size_t len)
{
	*current = (int *)malloc(sizeof(int) * len);
	if (*current == NULL)
		return (1);
	*prev = (int *)malloc(sizeof(int) * len);
	if (*prev == NULL)
	{
		free(current);
		return (1);
	}
	return (0);
}

static int	find_square(FILE *file, int *current, int *prev, t_data *data)
{
	if (read_all_lines(file, current, prev, data))
	{
		free_map(data->map, data->nb_lines);
		free(current);
		free(prev);
		return (1);
	}
	free(current);
	free(prev);
	return (0);
}

int	read_map(FILE *file, t_data *data)
{
	int		*current;
	int		*prev;

	if (create_map(file, data))
		return (1);
	if (create_int_lines(&current, &prev, (data->line_len - 1)))
	{
		free_map(data->map, 1);
		return (1);
	}
	if (handle_first_line(prev, data))
	{
		free_map(data->map, 1);
		free(current);
		free(prev);
		return (1);
	}
	if (find_square(file, current, prev, data))
		return (1);
	return (0);
}
