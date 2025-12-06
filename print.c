/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:23:44 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/22 17:44:21 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	display_map(char *line, t_data *data, int i)
{
	size_t	j;

	j = 0;
	while (j < (data->line_len - 1))
	{
		if (i >= (data->y - data->max + 1) && (i <= data->y)
			&& (int)j >= (data->x - data->max + 1) && ((int)j <= data->x))
		{
			fprintf(stdout, "%c", data->square);
		}
		else
			fprintf(stdout, "%c", line[j]);
		j++;
	}
	free(line);
}

int	print_map(FILE *file, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (i < data->nb_lines)
	{
		line = getline_bsq(file);
		if (line == NULL)
			return (1);
		display_map(line, data, i);
		fprintf(stdout, "%c", '\n');
		i++;
	}
	return (0);
}
