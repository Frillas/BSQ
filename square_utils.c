/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:36:16 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/22 18:57:41 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	check_min(int up, int diag, int left)
{
	if (up <= diag && up <= left)
		return (up);
	else if (diag <= up && diag <= left)
		return (diag);
	else
		return (left);
}

static void	add_square(char **map, t_data *data)
{
	int	i;
	int	j;

	j = data->y;
	while (j >= (data->y - (data->max - 1)))
	{
		i = data->x;
		while (i >= (data->x - (data->max - 1)))
		{
			map[j][i] = data->square;
			i--;
		}
		j--;
	}
}

static void	store_point(t_data *data, int num)
{
	data->max = num;
	data->x = data->j;
	data->y = data->i;
}

static void	process_cell(char *map, int *num, int *prev, t_data *data)
{
	int	j;

	j = data->j;
	if (map[j] == data->obstacle)
		num[j] = 0;
	else
	{
		if (j == 0)
			num[j] = check_min(prev[j], 0, 0) + 1;
		else
			num[j] = check_min(prev[j], prev[j - 1], num[j - 1]) + 1;
		if (data->max < num[j])
			store_point(data, num[j]);
	}
}

void	detect_square(char **map, int **num, t_data *data)
{
	int	i;

	data->i = 1;
	while (data->i < data->nb_lines)
	{
		data->j = 0;
		while (data->j < (data->line_len - 1))
		{
			i = data->i;
			process_cell(map[i], num[i], num[i - 1], data);
			data->j++;
		}
		data->i++;
	}
	add_square(map, data);
}
