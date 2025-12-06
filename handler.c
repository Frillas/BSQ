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
	data->i = 0;
	data->j = 0;
}

static int	rewind_file(FILE *file)
{
	char	*line;

	fseek(file, 0, SEEK_SET);
	line = getline_bsq(file);
	if (line == NULL)
		return (1);
	free(line);
	return (0);
}

int	handler(FILE *file)
{
	char	*line;
	t_data	data;

	line = getline_bsq(file);
	if (line == NULL)
		return (1);
	init_struct(&data);
	if (get_data(line, &data))
	{
		free(line);
		return (1);
	}
	free(line);
	if (read_map(file, &data))
		return (1);
	if (rewind_file(file))
		return (1);
	print_map(file, &data);
	return (0);
}
