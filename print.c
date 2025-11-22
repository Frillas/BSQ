#include "bsq.h"

void print_map(char **map, t_data *data)
{
	int i;

	for (i = 0; i < data->nb_lines; i++)
		fprintf(stdout, "%s", map[i]);
}
