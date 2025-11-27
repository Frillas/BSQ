/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:23:11 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/27 13:23:15 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	get_nb_lines(char *line, t_data *data, int *index)
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

int	get_map_data(char *line, t_data *data, int *index)
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

int	check_data(t_data *data)
{
	if (data->space != '\0' && data->obstacle != '\0' && data->square != '\0')
	{
		if (data->space == data->obstacle)
			return (1);
		else if (data->space == data->square)
			return (1);
		else if (data->obstacle == data->square)
			return (1);
		return (0);
	}
	return (1);
}

int	get_data(char *line, t_data *data)
{
	int	index;

	index = 0;
	if (get_nb_lines(line, data, &index))
		return (1);
	if (get_map_data(line, data, &index))
		return (1);
	if (check_data(data))
		return (1);
	return (0);
}
