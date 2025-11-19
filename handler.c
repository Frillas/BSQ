#include "bsq.h"

static int get_nb_lines(char *lineptr)
{
	int i = 0, nb_lines = 0;

	while (lineptr[i] >= '0' && (lineptr[i] <= '9'))
	{
		nb_lines = (nb_lines * 10) + (lineptr[i] - 48);
		i++;
	}
	if (i == 0)
		return (-1);

	printf("res = %d\n", nb_lines);

	free(lineptr);
	return (nb_lines);
}

int handler (FILE *file)
{
	char *lineptr, **map;
	int nb_lines = 0;

	lineptr = read_first_line(file);
	if (lineptr == NULL)
		return (1);

	nb_lines = get_nb_lines(lineptr);
	if (nb_lines == -1)
		return (1);

	map = read_all_lines(file, nb_lines);
	if (map == NULL)
		return (1);

	free_map(map, nb_lines);
	return (0);
}
