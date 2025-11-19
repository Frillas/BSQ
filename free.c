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
}
