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

void	handle_first_line(char *map, int *num, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (data->line_len - 1))
	{
		if (map[i] == data->space)
		{
			num[i] = 1;
			if (data->max < num[i])
			{
				data->max = num[i];
				data->x = i;
			}
		}
		else
			num[i] = 0;
		i++;
	}
}

int	check_min(int up, int diag, int left)
{
	if (up <= diag && up <= left)
		return (up);
	else if (diag <= up && diag <= left)
		return (diag);
	else
		return (left);
}

void	add_square(char **map, t_data *data)
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

void	process_cell(char **map, int **num, t_data *data, int i)
{
	int		*pnum;
	int		*prev;
	char	*pmap;
	int		j;

	j = data->j;
	pmap = map[i];
	pnum = num[i];
	prev = num[i - 1];
	if (pmap[j] == data->obstacle)
		pnum[j] = 0;
	else
	{
		if (j == 0)
			pnum[j] = check_min(prev[j], 0, 0) + 1;
		else
			pnum[j] = check_min(prev[j], prev[j - 1], pnum[j - 1]) + 1;
		if (data->max < pnum[j])
		{
			data->max = pnum[j];
			data->x = j;
			data->y = i;
		}
	}
}

void	detect_square(char **map, int **num, t_data *data)
{
	int	i;

	i = 1;
	while (i < data->nb_lines)
	{
		data->j = 0;
		while (data->j < (data->line_len - 1))
		{
			process_cell(map, num, data, i);
			data->j++;
		}
		i++;
	}
	add_square(map, data);
}
