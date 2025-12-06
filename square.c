/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:36:16 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/22 18:57:41 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	handle_first_line(int *current, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (data->line_len - 1))
	{
		if (data->map[0][i] == data->obstacle)
			current[i] = 0;
		else if (data->map[0][i] == data->space)
		{
			current[i] = 1;
			if (data->max < current[i])
			{
				data->max = current[i];
				data->x = i;
			}
		}
		else
			return (1);
		i++;
	}
	return (0);
}

static int	check_min(int up, int diag, int left)
{
	if (up <= diag && up <= left)
		return (up);
	else if (diag <= up && diag <= left)
		return (diag);
	else
		return (left);
}

static void	store_point(t_data *data, int num)
{
	data->max = num;
	data->x = data->j;
	data->y = data->i;
}

static int	process_cell(char *line, int *current, int *prev, t_data *data)
{
	int	j;

	j = data->j;
	if (line[j] == data->obstacle)
		current[j] = 0;
	else if (line[j] == data->space)
	{
		if (j == 0)
			current[j] = check_min(prev[j], 0, 0) + 1;
		else
			current[j] = check_min(prev[j], prev[j - 1], current[j - 1]) + 1;
		if (data->max < current[j])
			store_point(data, current[j]);
	}
	else
		return (1);
	return (0);
}

int	detect_square(char *line, int *current, int *prev, t_data *data)
{
	data->j = 0;
	while (data->j < (data->line_len - 1))
	{
		if (process_cell(line, current, prev, data))
		{
			free(line);
			return (1);
		}
		data->j++;
	}
	return (0);
}
