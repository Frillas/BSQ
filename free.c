#include "bsq.h"

void free_map(char **map, int nb_lines)
{
	int i = 0;

	while (i < nb_lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void free_int_map(int **int_map, int nb_lines)
{
	int i = 0;
	while (i < nb_lines)
	{
		free(int_map[i]);
		i++;
	}
	free(int_map);
	int_map = NULL;
}
