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
	if (c >= 32 && c <= 126)
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
