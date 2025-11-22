/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:23:19 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/22 18:28:28 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	open_file(char *argv[], FILE **file, int i)
{
	*file = fopen(argv[i], "r");
	if (*file == NULL)
	{
		fprintf(stderr, "map error\n");
		return (1);
	}
	return (0);
}

static int	check_args(int argc)
{
	if (argc < 2)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	FILE	*file;
	int		i;

	file = NULL;
	i = 1;
	if (check_args(argc))
	{
		handler(stdin);
		return (0);
	}
	while (i < argc)
	{
		if (i > 1)
			fprintf(stdout, "\n");
		open_file(argv, &file, i);
		if (file == NULL)
			continue ;
		if (handler(file))
			fprintf(stderr, "map error\n");
		fclose(file);
		file = NULL;
		i++;
	}
	return (0);
}
