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

char	**read_map(FILE *file, t_data *data)
{
	char	**map;

	map = (char **)malloc(data->nb_lines * sizeof(char *));
	if (map == NULL)
		return (NULL);
	if (read_all_lines(file, map, data))
		return (NULL);
	return (map);
}
