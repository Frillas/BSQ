/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:23:58 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/22 18:00:56 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	handle_one_line(char *map, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (data->line_len - 1))
	{
		if (map[i] == data->space)
		{
			map[i] = data->square;
			break ;
		}
		i++;
	}
}

static void	handle_first_line(char *map, int *num, t_data *data)
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

int	find_square(char **map, t_data *data)
{
	int	**num;

	if (data->nb_lines == 1)
	{
		handle_one_line(map[0], data);
		return (0);
	}
	num = create_int_map(data);
	if (num == NULL)
		return (1);
	handle_first_line(map[0], num[0], data);
	detect_square(map, num, data);
	free_int_map(num, data->nb_lines);
	return (0);
}
