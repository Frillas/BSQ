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

static int	check_nb_lines(char *line, t_data *data)
{
	if (data->i >= data->nb_lines)
	{
		free(line);
		return (1);
	}
	return (0);
}

int	check_line_size(char *line, t_data *data)
{
	size_t	size;

	size = strlen_bsq(line);
	if (data->i == 0)
		data->line_len = size;
	if (size != data->line_len || line[size - 1] != '\n')
	{
		free(line);
		return (1);
	}
	return (0);
}

static void	buffer_exchange(int **current, int **prev)
{
	int	*tmp;

	tmp = *current;
	*current = *prev;
	*prev = tmp;
}

int	read_all_lines(FILE *file, int *current, int *prev, t_data *data)
{
	char	*line;

	data->i = 1;
	while (1)
	{
		line = getline_bsq(file);
		if (line == NULL)
			break ;
		if (check_nb_lines(line, data))
			return (1);
		if (check_line_size(line, data))
			return (1);
		if (detect_square(line, current, prev, data))
			return (1);
		buffer_exchange(&current, &prev);
		free(line);
		data->i++;
	}
	if (data->i < data->nb_lines)
		return (1);
	return (0);
}
