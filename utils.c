/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:24:05 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/22 18:29:59 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	isalnum_bsq(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}

size_t	strlen_bsq(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strcpy_bsq(char *str)
{
	int		len;
	int		i;
	char	*new_str;

	len = 0;
	i = 0;
	if (str == NULL)
		return (NULL);
	len = strlen_bsq(str);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*getline_bsq(FILE *file)
{
	char	*line;
	size_t	n;
	ssize_t	nb_bytes;

	line = NULL;
	n = 0;
	nb_bytes = 0;
	nb_bytes = getline(&line, &n, file);
	if (nb_bytes < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	**create_int_map(t_data *data)
{
	int	i;
	int	**new_map;

	i = 0;
	new_map = (int **)malloc((data->nb_lines) * sizeof(int *));
	if (new_map == NULL)
		return (NULL);
	while (i < data->nb_lines)
	{
		new_map[i] = (int *)malloc((data->line_len - 1) * sizeof(int));
		if (new_map[i] == NULL)
		{
			free_int_map(new_map, i);
			return (NULL);
		}
		i++;
	}
	return (new_map);
}
